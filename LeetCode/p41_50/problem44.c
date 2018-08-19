//
//  problem44.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/19.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem44.h"

bool isMatch44_1(char* s, char* p) {
    if (strlen(s) == 0) {
        if (strlen(p) > 0 && p[0] == '*') {
            return isMatch(s, p+1);
        } else if (strlen(p) == 0){
            return true;
        } else {
            return false;
        }
    } else if (strlen(p) == 0) {
        return false;
    }
    //这里s长度不为0，p长度也不为0
    //p遇到 ?
    if (p[0] == '?') {
        return isMatch(s+1, p+1);
    } else if (p[0] == '*') {
        bool re = false;
        for (int i = 0; i <= strlen(s) && re == false; i++) {
            re = isMatch(s+i, p+1);
        }
        return re;
    } else {
        return p[0] == s[0] && isMatch(s+1,p+1);
    }
}

bool isMatch44(char* s, char* p) {
    //去掉连续的*
    char *newp = malloc(sizeof(char) * (strlen(p) + 1));
    int pos = 0;
    for (int i = 0; i < strlen(p); i++) {
        if (pos > 0 && newp[pos - 1] == '*' && p[i] == '*') {
            continue;
        } else {
            newp[pos++] = p[i];
        }
    }
    newp[pos] = '\0';
    return isMatch44_1(s, newp);
}
