//
//  problem20.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/18.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem20.h"

bool isValidWithStack(char cur, char **last) {
    if (cur == 0 && strlen(*last) == 0) {
        return true;
    } else if (**last == ')' || **last == ']' || **last == '}') {
        char a = **last;
        bool t = false;
        if (a == ')' && cur == '(') {
            t = true;
        } else if (a == ']' && cur == '[') {
            t = true;
        } else if (a == '}' && cur == '{') {
            t = true;
        }
        *last = *last + 1;
        return t;
    } else if (**last == '(' || **last == '[' || **last == '{'){
        char next = **last;
        *last = *last+1;
        bool t = isValidWithStack(next, last);
        return t && isValidWithStack(cur, last);
    } else {
        return false;
    }
}


bool isValid(char* s) {
    char **t = &s;
    return isValidWithStack(0, t);
}
