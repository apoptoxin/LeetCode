//
//  problem49.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/27.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem49.h"
#include <stdlib.h>

struct StringNode {
    char *origin;
    int pos;
    char *sorted;
};

int cmpfunc49Node (const void * a, const void * b)
{
    struct StringNode** t1 = (struct StringNode**)a;
    struct StringNode** t2 = (struct StringNode**)b;
    return strcmp((*t1)->sorted, (*t2)->sorted);
}

int cmpfunc49str(const void * a, const void * b)
{
    return ( *(char*)a - *(char*)b );
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    //对每个单词进行sort
    struct StringNode **list = malloc(sizeof(struct StringNode *) * strsSize);
    for (int i = 0 ; i < strsSize ; i++) {
        struct StringNode *cur = malloc(sizeof(struct StringNode));
        cur->pos = i;
        cur->origin = strs[i];
        char *s = malloc(sizeof(char) * strlen(strs[i]));
        strcpy(s, strs[i]);
        qsort(s,strlen(strs[i]),sizeof(char),cmpfunc49str);
        cur->sorted = s;
        list[i] = cur;
    }
    qsort(list, strsSize, sizeof(struct StringNode*), cmpfunc49Node);
    char ***result = malloc(sizeof(char**) * strsSize);
    int *counts = NULL;
    int countNum = 0;
    int pos = 0;
    for (int i = 0, from = 0; i <= strsSize ; i++) {
        if ((i == strsSize) || (i != 0 && strcmp(list[i]->sorted, list[i-1]->sorted) != 0)) {
            //from 到 i-1是相同的，构成一个char**
            char ** tmp = malloc(sizeof(char *) * i-from);
            for (int j = 0 ; j <(i == strsSize - 1)?i+1-from:i-from ; j++) {
                tmp[j] = list[from+j]->origin;
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
