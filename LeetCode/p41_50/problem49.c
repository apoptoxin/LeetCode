//
//  problem49.c
//  LeetCode
//
//  Created by apoptoxin on 2018/8/27.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem49.h"
#include <stdlib.h>

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    //对每个单词进行sort
    int  groupCount = 0;
    int** allKeys = NULL;
    int* curColumnSizes = NULL;
    char ***result = NULL;
    
    for (int i = 0 ; i < strsSize ; i++) {
        //step 1,构造key数组，表示字母'a。。。'出现了几次
        int *keys = calloc(26,sizeof(int));
        char *cur = strs[i];
        int length = strlen(cur);
        for (int j = 0 ; j < length; j++) {
            int p = cur[j] - 'a';
            keys[p] ++;
        }
        for (int p = 0 ; p < 26 ; p++) {
            printf("%d ",keys[p]);
        }
        printf("\n");
        if (groupCount == 0) {
            allKeys = malloc(sizeof(int *));
            allKeys[0] = keys;
            
            curColumnSizes = malloc(sizeof(int));
            curColumnSizes[0] = 1;
            
            groupCount = 1;
            
            result = malloc(sizeof(char **));
            result[0] = malloc(sizeof(char *));
            result[0][0] = cur;
        } else {
            int pos = 0;
            int notMatch = 0;
            for (int k = 0 ; k < groupCount; k++) {
                notMatch = 0;
                int *curK = allKeys[k];
                for (int m = 0; m < 26; m++) {
                    if (curK[m] != keys[m]) {
                        notMatch = 1;
                        break;
                    }
                }
                if (notMatch) {
                    pos++;
                    continue;
                } else {
                    break;
                }
            }
                
            if (pos >= groupCount) {
                //没找到
                allKeys = realloc(allKeys, sizeof(int*)*(groupCount+1));
                allKeys[groupCount] = keys;
                
                curColumnSizes = realloc(curColumnSizes, sizeof(int)*(groupCount+1));
                curColumnSizes[groupCount] = 1;
                
                result = realloc(result, sizeof(char **)*(groupCount+1));
                result[groupCount] = malloc(sizeof(char *));
                result[groupCount][0] = cur;
                groupCount++;
            } else {
                //找到了，第pos个
                //key不用管了
                curColumnSizes[pos] ++;
                
                result[pos] = realloc(result[pos], sizeof(char*)*curColumnSizes[pos]);
                result[pos][curColumnSizes[pos]-1] = cur;
            }
        }
    }
    if (returnSize) {
        *returnSize = groupCount;
    }
    if (columnSizes) {
        *columnSizes = curColumnSizes;
    }
    return result;
}
