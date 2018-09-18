//
//  problem65.c
//  LeetCode
//
//  Created by 刘楠 on 2018/9/17.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem65.h"

bool isNumberAfterE(char *s);

bool isDot(char s) {
    return s == '.';
}

bool charIsNumber(char s) {
    return s - '0' < 10 && s - '0' >= 0;
}

bool isPureNumber(char *s) {
    int totalLength = strlen(s);
    int i = 0;
    for (i = 0; i <totalLength; i++) {
        if (charIsNumber(s[i])) {
            continue;
        } else {
            break;
        }
    }
    return i >= totalLength;
}

bool isPureSpace(char *s) {
    int totalLength = strlen(s);
    int i = 0;
    for (i = 0; i <totalLength; i++) {
        if (s[i] == ' ') {
            continue;
        } else {
            break;
        }
    }
    return i >= totalLength;
}

bool isNumberAfterDot(char *s,bool preHasNum) {
    //点之后只能是数字或者e
    bool result = preHasNum;
    int totalLength = strlen(s);
    int i = 0;
    for (; i < totalLength; i++) {
        if (charIsNumber(s[i])) {
            result = true;
            continue;
        } else {
            break;
        }
    }
    if (i >= totalLength || isPureSpace(s+i)) {
        return result;
    } else if (s[i] == 'e') {
        i++;
        if (i >= totalLength || isPureSpace(s+i)) {
            return false;
        }
        return result && isNumberAfterE(s+i);
    }
    return false;
}

bool isNumberAfterE(char *s) {
    //e后面只能有数字，+-
    bool result = false;
    int totalLength = strlen(s);
    int i = 0;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    if (i >= totalLength) {
        return false;
    }
    for (; i < totalLength; i++) {
        if (charIsNumber(s[i])) {
            result = true;
            continue;
        } else {
            break;
        }
    }
    if (i >= totalLength || isPureSpace(s+i)) {
        return result;
    }
    return false;
}

bool isNumber(char* s) {
    bool result = false;
    int totalLength = strlen(s);
    int i = 0;
    for (; i < totalLength; i++) {
        if (s[i] == ' ') {
            continue;
        } else {
            break;
        }
    }
    if (i >= totalLength) {
        return result;
    }
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    if (i >= totalLength) {
        return result;
    }
    for (; i < totalLength; i++) {
        if (charIsNumber(s[i])) {
            result = true;
            continue;
        } else {
            break;
        }
    }
    if (i >= totalLength || isPureSpace(s+i)) {
        return true;
    }
    if (s[i] == '.') {
        i++;
        return isNumberAfterDot(s+i,result);
    }
    if (s[i] == 'e') {
        i++;
        return result && isNumberAfterE(s+i);
    }
    if (i >= totalLength || isPureSpace(s+i)) {
        return result;
    } else {
        return false;
    }
}
