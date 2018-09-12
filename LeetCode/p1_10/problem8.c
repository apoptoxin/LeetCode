//
//  problem8.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/3.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem8.h"

int myAtoi(char* str) {
    int max = (pow(2,30) - 1) * 2 + 1;
    int min = -1 * max - 1;
    int temp = 0;
    //去空格
    while (str[0] == ' ') {
        str++;
    }
    if (str[0] == '\0') {
        return 0;
    }
    int mul = 1;
    //正负数
    if (str[0] == '-') {
        mul = -1;
        str++;
    } else if (str[0] == '+') {
        mul = 1;
        str++;
    } else if (str[0] < '0' || str[0] > '9') {
        return 0;
    }
    while(str[0] <= '9' && str[0] >= '0') {
        int addition = (str[0] - '0')*mul;
        if (temp < 0 && temp < (min - addition) / 10) {
            return min;
        } else if (temp > 0 && temp > (max - addition) / 10) {
            return max;
        } else {
            temp = temp * 10 + addition;
        }
        str++;
    }
    return temp;
}
