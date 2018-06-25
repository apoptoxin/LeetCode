//
//  problem3.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/25.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem3.h"

int lengthOfLongestSubstring(char* s) {
    int map[10000];
    for (int i = 0; i < 10000 ; i++) {
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
