//
//  problem70.c
//  LeetCode
//
//  Created by 刘楠 on 2018/11/8.
//  Copyright © 2018 micronil.com. All rights reserved.
//

#include "problem70.h"

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    int x = 1;
    int y = 2;
    for (int i = 3; i<=n; i++) {
        int tmp = x+y;
        x=y;
        y=tmp;
    }
    return y;
}
