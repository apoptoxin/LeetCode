//
//  problem93.c
//  LeetCode
//
//  Created by liunan on 2019/7/10.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem93.h"

void validAndRestore(int* axis, int level, char *s, int totalLength, int* returnSize, char*** result);

char ** restoreIpAddresses(char * s, int* returnSize){
    char **result = NULL;
    int resultSize = 0;
    int* axis = calloc(4, sizeof(int));
    validAndRestore(axis, 0, s, strlen(s), &resultSize, &result);
    if (returnSize) {
        *returnSize = resultSize;
    }
    return result;
}

void validAndRestore(int* axis, int level, char *s, int totalLength, int* returnSize, char*** result) {
    if (level == 3) {
        //这时axis有3个值，只校验最后一个就行
        if (totalLength - axis[2] <= 0 || totalLength - axis[2] > 3 || (totalLength - axis[2] > 1 && s[axis[2]] == '0')) {
            //最后一个数大于了1000，或者是以0开头但是不只有一位，无效
            return;
        }
        int tmp = 0;
        for (int i = axis[2]; i < totalLength; i++) {
            int cur = s[i] - '0';
            if (cur < 0 || cur > 9) {
                return;
            }
            tmp = tmp * 10 + (s[i] - '0');
        }
        if (tmp > 255) {
            return;
        }
        //去掉不合规的
        char *value = malloc(sizeof(char) * (totalLength+4));
        for (int i = 0, j = 0; i <totalLength; i++,j++) {
            value[j] = s[i];
            if (i == axis[0]-1 || i == axis[1]-1 || i==axis[2]-1) {
                value[++j] = '.';
            }
        }
        value[totalLength+3] = '\0';
        if (*returnSize == 0) {
            *returnSize = 1;
            *result = malloc(sizeof(char *));
            (*result)[0] = value;
        } else {
            *result = realloc(*result, sizeof(int*) * (*returnSize + 1));
            (*result)[*returnSize] = value;
            *returnSize = *returnSize + 1;
        }
    } else {
        int tmpPos = level == 0 ? 0 : axis[level-1];
        int tmp = 0;
        for (int i = tmpPos; i < tmpPos + 3 && i < totalLength; i++) {
            int cur = s[i] - '0';
            if (cur < 0 || cur > 9) {
                //不是数字的直接返回
                return;
            }
            if (tmp == 0 && tmpPos < i) {
                return;
            }
            tmp = tmp * 10 + cur;
            if ((tmp == 0 && tmpPos == i) || (tmp > 0 && tmp <= 255)) {
                axis[level] = i+1;
                validAndRestore(axis, level+1, s, totalLength, returnSize, result);
            }
        }
    }
}
