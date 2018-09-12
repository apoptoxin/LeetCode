//
//  problem17.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/13.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem17.h"

int sizeForSingleNumber(int i) {
    if (i == 7 || i == 9) {
        return 4;
    } else if(i > 1 && i < 10){
        return 3;
    } else {
        return 0;
    }
}

char* charForSingleNumber(int i, int *size) {
    *size = sizeForSingleNumber(i);
    if (i == 2) {
        return "abc";
    } else if (i == 3) {
        return "def";
    } else if (i == 4) {
        return "ghi";
    } else if (i == 5) {
        return "jkl";
    } else if (i == 6) {
        return "mno";
    } else if (i == 7) {
        return "pqrs";
    } else if (i == 8) {
        return "tuv";
    } else if (i == 9) {
        return "wxyz";
    } else {
        return "";
    }
}

char ** letterForDigit(char* prefix , int curDigit, int* returnSize) {
    if (curDigit < 2 || curDigit > 9) {
        return NULL;
    }
    int count = 0;
    char *letters = charForSingleNumber(curDigit, &count);
    *returnSize = count;
    char **result = (char **)malloc(sizeof(char*) * count);
    for (int i = 0 ; i < count ; i++) {
        int l = (strlen(prefix)+2);
        char *curStr = (char*)malloc(l*sizeof(char));
        for(int j = 0; j < l-2;j++) {
            curStr[j] = prefix[j];
        }
        curStr[l-2] = letters[i];
        curStr[l-1] = '\0';
        result[i] = curStr;
    }
    return result;
}

char** letterCombinations(char* digits, int* returnSize) {
    int digitCount = strlen(digits);
    char** result = NULL;
    int letterSize = 0;
    for (int i = 0 ; i < digitCount ; i++) {
        int curDigit = digits[i] - '0';
        int curSize = 0;
        if (i == 0) {
            //初始
            result = letterForDigit("", curDigit, &curSize);
            letterSize = curSize;
        } else {
            int c = 0;
            char **t = result;
            for (int j = 0; j < letterSize; j++) {
                char **temp = letterForDigit(t[j], curDigit, &curSize);
                if (j == 0) {
                    result = malloc(sizeof(char*) * curSize);
                } else {
                    result = realloc(result, sizeof(char*)*(c+curSize));
                }
                
                for (int k = 0 ; k < curSize ; k++,c++) {
                    result[c] = temp[k];
                }
            }
            letterSize = c;
        }
        *returnSize = letterSize;
    }
    for (int i = 0 ; i < *returnSize; i++) {
        char *t = result[i];
        int length = strlen(t);
        t = realloc(t, sizeof(char) * (length + 1));
        t[length]='\0';
        result[i] = t;
        printf("%s\n",result[i]);
    }
    return result;
}

