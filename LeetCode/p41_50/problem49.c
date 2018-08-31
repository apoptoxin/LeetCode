//
//  problem49.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/27.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem49.h"
#include <stdlib.h>

int cmpfunc49str(const void * a, const void * b)
{
    return ( *(char*)a - *(char*)b );
}

int cmpfunc49Node (const void * a, const void * b)
{
    char **t1 = a;
    char **t2 = b;
    char *s1 = malloc(sizeof(char) * strlen(*t1));
    char *s2 = malloc(sizeof(char) * strlen(*t2));
    strcpy(s1, *t1);
    strcpy(s2, *t2);
    qsort(s1, strlen(s1), sizeof(char), cmpfunc49str);
    qsort(s2, strlen(s2), sizeof(char), cmpfunc49str);
    int result = strcmp(s1, s2);
    free(s1);
    free(s2);
    return result;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    //对每个单词进行sort
    qsort(strs, strsSize, sizeof(char*), cmpfunc49Node);
    char ***result = malloc(sizeof(char**) * strsSize);
    int *counts = malloc(sizeof(int) * strsSize);
    int countNum = 0;
    int pos = 0;
    for (int i = 0, from = 0; i <= strsSize ; i++) {
        int r = 1;
        if (i != strsSize && i > 0) {
            char *s1 = malloc(sizeof(char) * strlen(strs[i]));
            char *s2 = malloc(sizeof(char) * strlen(strs[i-1]));
            strcpy(s1, strs[i]);
            strcpy(s2, strs[i-1]);
            qsort(s1, strlen(s1), sizeof(char), cmpfunc49str);
            qsort(s2, strlen(s2), sizeof(char), cmpfunc49str);
            r = strcmp(s1, s2);
            free(s1);
            free(s2);
        }
        
        if (i > 0 && r != 0) {
            //from 到 i-1是相同的，构成一个char**
            char ** tmp = malloc(sizeof(char *) * i-from);
            int max = ((i == strsSize - 1)?i+1-from:i-from);
            for (int j = 0 ; j < max ; j++) {
                tmp[j] = strs[from+j];
            }
            if (counts == NULL) {
                counts = malloc(sizeof(int));
                counts[0] = i - from;
                countNum = 1;
            } else {
                ++countNum;
                counts = realloc(counts, sizeof(int) * countNum);
                counts[countNum-1] = i - from;
            }
            result[pos++] = tmp;
            from = i;
        } else {
            continue;
        }
    }
    if (returnSize) {
        *returnSize = countNum;
    }
    if (columnSizes) {
        *columnSizes = counts;
    }
    return result;
}
