//
//  problem51.c
//  LeetCode
//
//  Created by apoptoxin on 2018/9/2.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem51.h"

int canSet(int *table, int n, int depth, int pos) {
//    for (int i = 0 ; i < n ; i++) {
//        printf("%d ",table[i]);
//    }
//    printf("\n");
    //table中设置第i个如果占用过的话值为depth+1，否则为0
    for (int i = 0 ; i < n ; i++) {
        if (i > pos && table[i] == depth + 1 - (i-pos) && table[i] > 0) {
            return 0;
        }
        if (i < pos && table[i] == depth + 1 - (pos-i) && table[i] > 0) {
            return 0;
        }
        if (i == pos && table[i] > 0) {
            return 0;
        }
    }
    return 1;
}

char **copyFromOrigin(char **ori,int size) {
    char** re = malloc(sizeof(char *) * size);
    for (int i = 0 ; i < size ; i++) {
        re[i] = malloc(sizeof(char) * (size+1));
        for (int j = 0 ; j < size ; j++) {
            re[i][j] = ori[i][j];
        }
        re[i][size] = '\0';
    }
    return re;
}

void solveNQueensWithDepth(int n, int depth, int*tmp, char** cur, char**** results, int *resultSize) {
    if (n <= depth) {
        char ***table = *results;
        if (*resultSize == 0) {
            //第一个解
            table = malloc(sizeof(char**));
            table[0] = copyFromOrigin(cur, n);
            *resultSize = 1;
        } else {
            table = realloc(table, sizeof(char **) *((*resultSize) + 1));
            table[(*resultSize)] = copyFromOrigin(cur, n);
            *resultSize = (*resultSize) + 1;
        }
        *results = table;
        return;
    }
    //初始化第depth行的所有都为.
    for (int i = 0 ; i < n; i++) {
        cur[depth][i] = '.';
    }
    for (int i = 0 ; i < n; i++) {
        if (canSet(tmp, n, depth, i)) {
            cur[depth][i] = 'Q';
            tmp[i] = depth+1;
            solveNQueensWithDepth(n, depth+1, tmp, cur, results, resultSize);
            tmp[i] = 0;
            cur[depth][i] = '.';
        }
    }
}

char*** solveNQueens(int n, int* returnSize) {
    char ***re = 0;
    int size = 0;
    int *tmp = calloc(n, sizeof(int));
    char **cur = malloc(sizeof(char*)*n);
    for (int i = 0 ; i < n ; i++) {
        cur[i] = malloc(sizeof(char) * n);
    }
    solveNQueensWithDepth(n, 0, tmp, cur, &re, &size);
    if (returnSize) {
        *returnSize = size;
    }
    return re;
}
