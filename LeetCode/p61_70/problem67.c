//
//  problem67.c
//  LeetCode
//
//  Created by liunan on 2018/11/6.
//  Copyright © 2018 micronil.com. All rights reserved.
//

#include "problem67.h"

char* addBinary(char* a, char* b) {
    int lengtha = strlen(a);
    int lengthb = strlen(b);
    int addition = 0;
    int total = lengtha > lengthb ? lengtha + 1 : lengthb + 1;
    char *s = malloc(sizeof(char) * (total+1));
    s[total] = '\0';
    for (int i = lengtha - 1, j = lengthb - 1,k = total-1; i >=0 || j >= 0; i--,j--,k--) {
        int ac = i>=0 ? a[i] - '0' : 0;
        int bc = j>=0 ? b[j] - '0' : 0;
        s[k] = '0' + ((ac+bc+addition) % 2);
        addition = (ac+bc+addition) / 2;
    }
    if (addition > 0) {
        s[0] = '0' + addition;
        return s;
    } else {
        return &(s[1]);
    }
}
