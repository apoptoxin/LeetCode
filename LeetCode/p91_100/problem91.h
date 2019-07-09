//
//  problem91.h
//  LeetCode
//
//  Created by liunan on 2019/7/9.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef problem91_h
#define problem91_h

#include <stdio.h>

#endif /* problem91_h */

int numDecodings(char * s){
    int totalLen = strlen(s);
    if (totalLen <= 0) {
        return 0;
    } else if (totalLen == 1) {
        return s[0] == '0' ? 0 : 1;
    }
    int tmp = 1;
    int result = s[0] == '0' ? 0 : 1;
    for (int i = 1; i < totalLen; i++) {
        int cur = s[i] - '0';
        int pre = s[i-1] - '0';
        if (cur == 0) {
            if (pre * 10 + cur < 10 || pre * 10 + cur > 20) {
                tmp = result;
                result = 0;
            } else {
                tmp = tmp ^ result;
                result = result ^ tmp;
                tmp = tmp ^ result;
            }
        } else if (pre * 10 + cur <= 26 && pre > 0) {
            //10~26
            result = tmp + result;
            tmp = result - tmp;
        } else {
            tmp = result;
        }
    }
    return result;
}
