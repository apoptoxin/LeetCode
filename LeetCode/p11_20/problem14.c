//
//  problem14.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/11.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem14.h"

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    } else {
        int length = strlen(strs[0]);
        for (int i = 1; i < strsSize ; i++) {
            int k = 0;
            int curLength = strlen(strs[i]);
            for (; k < curLength && k < length && strs[i][k] == strs[0][k]; k++);
            length = length < k ? length : k;
        }
        char *result = malloc(sizeof(char) * (length + 1));
        result[length] = '\0';
        for (int i = 0; i < length; i++) {
            result[i] = strs[0][i];
        }
        return result;
    }
}
