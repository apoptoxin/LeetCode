//
//  problem7.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/3.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem7.h"

int reverse(int x) {
    int max = (pow(2,30) - 1) * 2 + 1;
    int min = -1 * max - 1;
    int temp = 0;
    while (x != 0) {
        int addition = x % 10;
        if ((x<0 && temp < (min - addition) / 10) || (x >= 0 && temp > (max - addition) / 10)) {
            return 0;
        } else {
            temp = temp * 10 + addition;
        }
        x = x/10;
    }
    return temp;
}
