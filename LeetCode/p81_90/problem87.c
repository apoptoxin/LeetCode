//
//  problem87.c
//  LeetCode
//
//  Created by liunan on 2019/7/1.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem87.h"

bool scrambleForString(char *s1, int start1, int end1, char *s2, int start2, int end2);

bool isScramble(char * s1, char * s2){
    return scrambleForString(s1, 0, strlen(s1), s2, 0, strlen(s2));
}

bool scrambleForString(char *s1, int start1, int end1, char *s2, int start2, int end2) {
    if (end1 - start1 <= 0 || end2 - start2 <= 0 || end1 - start1 != end2 - start2) {
        return false;
    }
    if (end1 - start1 == 1) {
        //只有一个
        return s1[start1] == s2[start2];
    }
    if (end1 - start1 == 2) {
        //有两个
        return (s1[start1] == s2[start2] && s1[end1-1] == s2[end2-1]) || (s1[start1] == s2[end2-1] && s1[end1-1] == s2[start2]);
    }
    bool flag = false;
    for (int i = 1 ; i < end1 - start1; i++) {
        flag = flag || (scrambleForString(s1, start1, start1+i, s2, start2, start2+i) && scrambleForString(s1, start1+i, end1, s2, start2+i, end2)) || (scrambleForString(s1, start1, start1+i, s2, end2-i, end2) && scrambleForString(s1, start1+i, end1, s2, start2, end2-i));
    }
    return flag;
}
