//
//  problem3.c
//  LeetCode
//
//  Created by apoptoxin on 2018/6/25.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem3.h"

int lengthOfLongestSubstring(char* s) {
    //标准ASCII只有128个字符,后来IBM扩展为256个字符,被称为扩展ASCII,但现在不属于国际标准
    int map[128];
    for (int i = 0; i < 128 ; i++) {
        map[i] = -1;
    }
    int len = (int)strlen(s);
    int totalLength = 0;
    for (int i = 0, curLength = 0; i < len ; i++) {
        int pos = s[i];
        if (map[pos] == -1 || i - map[pos] > curLength) {
            curLength ++;
            if (curLength > totalLength) {
                totalLength = curLength;
            }
        } else {
            curLength = i - map[pos];
        }
        map[pos] = i;
    }
    return totalLength;
}
