//
//  problem13.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/9.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem13.h"
#include "bool_define.h"

int intForSingleRoman(char* s,int length, bool *valid) {
    *valid = true;
    if (length == 1) {
        if (s[0] == 'I') {
            return 1;
        } else if (s[0] == 'V') {
            return 5;
        } else if (s[0] == 'X') {
            return 10;
        } else if (s[0] == 'L') {
            return 50;
        } else if (s[0] == 'C') {
            return 100;
        } else if (s[0] == 'D') {
            return 500;
        } else if (s[0] == 'M') {
            return 1000;
        } else {
            *valid = 0;
            return 0;
        }
    } else if (length == 2) {
        if (s[0] == 'I') {
            if (s[1] == 'V') {
                return 4;
            } else if (s[1] == 'X') {
                return 9;
            } else {
                *valid = false;
                return 0;
            }
        } else if (s[0] == 'X') {
            if (s[1] == 'L') {
                return 40;
            } else if (s[1] == 'C') {
                return 90;
            } else {
                *valid = false;
                return 0;
            }
        } else if (s[0] == 'C') {
            if (s[1] == 'D') {
                return 400;
            } else if (s[1] == 'M') {
                return 900;
            } else {
                *valid = false;
                return 0;
            }
        } else {
            *valid = false;
            return 0;
        }
    } else {
        *valid = false;
        return 0;
    }
}

int romanToInt(char* s) {
    int length = strlen(s);
    int total = 0;
    for (int i = 0; i < length ;) {
        bool valid = false;
        int curVal = 0;
        //先试两个
        if (i+1 < length) {
            curVal = intForSingleRoman(s+i, 2, &valid);
        }
        if (valid) {
            total += curVal;
            i+=2;
        } else {
            curVal = intForSingleRoman(s+i, 1, &valid);
            if (valid) {
                total += curVal;
                i += 1;
            } else {
                return 0;
            }
        }
    }
    return total;
}
