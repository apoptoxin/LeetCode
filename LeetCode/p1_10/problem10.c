//
//  problem10.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/7.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem10.h"

bool isMatch(char* s, char* p) {
    //判断p中头部有没有星号
    if (strlen(p) == 0) {
        if (strlen(s) == 0) {
            return true;
        } else {
            return false;
        }
    } else if (strlen(p) == 1) {
        if (p[0] == '*') {
            return false;
        } else if (strlen(s) == 1) {
            if (p[0] == '.' || (p[0] == s[0])) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        //判断p[1]是否为*
        if (p[1] == '*') {
            bool curMatch = false;
            if (p[0] == '.') {
                for (int i = 1 ; i <= strlen(s); i++) {
                    curMatch = curMatch || isMatch(s+i, p+2);
                }
            } else {
                for (int i = 0 ; i < strlen(s) && s[i] == p[0]; i++) {
                    curMatch = curMatch || isMatch(s+i+1, p+2);
                }
            }
            return curMatch || isMatch(s, p+2);
        } else {
            if (p[0] == '.') {
                return strlen(s) != 0 && isMatch(s+1, p+1);
            } else {
                return strlen(s) != 0 && p[0] == s[0] && isMatch(s+1, p+1);
            }
        }
    }
    return false;
}
