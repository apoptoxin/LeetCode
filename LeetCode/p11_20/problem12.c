//
//  problem12.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/9.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem12.h"
#include <stdlib.h>

int curNumFromInt(int num) {
    if (num >= 1000) {
        return 1000;
    } else if (num >= 900) {
        return 900;
    } else if (num >= 500) {
        return 500;
    } else if (num >= 400) {
        return 400;
    } else if (num >= 100) {
        return 100;
    } else if (num >= 90) {
        return 90;
    } else if (num >= 50) {
        return 50;
    } else if (num >= 40) {
        return 40;
    } else if (num >= 10) {
        return 10;
    } else if (num >= 9) {
        return 9;
    } else if (num >= 5) {
        return 5;
    } else if (num >= 4) {
        return 4;
    } else if (num >= 1) {
        return 1;
    } else {
        return 0;
    }
}

char *romanStringForNum(int num , int *length) {
    if (num >= 1000) {
        *length = 1;
        return "M";
    } else if (num >= 900) {
        *length = 2;
        return "CM";
    } else if (num >= 500) {
        *length = 1;
        return "D";
    } else if (num >= 400) {
        *length = 2;
        return "CD";
    } else if (num >= 100) {
        *length = 1;
        return "C";
    } else if (num >= 90) {
        *length = 2;
        return "XC";
    } else if (num >= 50) {
        *length = 1;
        return "L";
    } else if (num >= 40) {
        *length = 2;
        return "XL";
    } else if (num >= 10) {
        *length = 1;
        return "X";
    } else if (num >= 9) {
        *length = 2;
        return "IX";
    } else if (num >= 5) {
        *length = 1;
        return "V";
    } else if (num >= 4) {
        *length = 2;
        return "IV";
    } else if (num >= 1) {
        *length = 1;
        return "I";
    } else {
        *length = 0;
        return "";
    }
}

char* intToRoman(int num) {
    char *temp = (char *)malloc(sizeof(char) * 35);
    int totalLength = 0;
    while (num > 0) {
        int cur = curNumFromInt(num);
        num -= cur;
        int length = 0;
        char *curStr = romanStringForNum(cur, &length);
        for (int k = 0; k < length; k++) {
            temp[totalLength + k] = curStr[k];
        }
        totalLength += length;
    }
    char *result = (char *)malloc(sizeof(char) *(totalLength + 1));
    for (int i = 0 ; i < totalLength ; i++) {
        result[i] = temp[i];
    }
    result[totalLength] = '\0';
    free(temp);
    return result;
}
