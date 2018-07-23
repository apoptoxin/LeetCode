//
//  problem22.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/23.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem22.h"

char** generateParenthesisWithLeftAndRightCount(char* prefix, int left, int right, int n ,int* returnSize) {
    int prefixLength = (int)strlen(prefix);
    int count = 0;
    char** result = NULL;
    if (left == right && left == n) {
        if (strlen(prefix) > 0) {
            result = (char**)malloc(sizeof(char*));
            result[0] = prefix;
            *returnSize += 1;
        }
        return result;
    }
    if (n-left>0) {
        char *tmp = malloc(sizeof(char) *(prefixLength+2));
        strcpy(tmp,prefix);
        tmp[prefixLength] = '(';
        tmp[prefixLength+1] = '\0';
        result = generateParenthesisWithLeftAndRightCount(tmp, left+1, right, n, &count);
    }
    if(right<left) {
        char *tmp = malloc(sizeof(char) *(prefixLength+2));
        strcpy(tmp,prefix);
        tmp[prefixLength] = ')';
        tmp[prefixLength+1] = '\0';
        int tmpCount = 0;
        char **tmpRight = generateParenthesisWithLeftAndRightCount(tmp, left, right+1, n, &tmpCount);
        result = realloc(result, (count+tmpCount) * sizeof(char*));
        for (int i = 0; i < tmpCount ; i++) {
            result[count+i] = tmpRight[i];
        }
        count += tmpCount;
    }
    *returnSize += count;
    return result;
}

char** generateParenthesis(int n, int* returnSize) {
    char *s = malloc(sizeof(char));
    s[0] = '\0';
    return generateParenthesisWithLeftAndRightCount(s, 0, 0, n, returnSize);
}
