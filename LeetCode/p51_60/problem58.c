//
//  problem58.c
//  LeetCode
//
//  Created by apoptoxin on 2018/9/11.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem58.h"

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int total = 0;
    
    for (int i = 0 ; i < len ; i++) {
        if (s[i] == ' ') {
            continue;
        } else {
            if (i > 0 && s[i-1] == ' ') {
                total = 1;
            } else{
                total++;
            }
        }
    }
    return total;
}
