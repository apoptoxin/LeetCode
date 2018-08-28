//
//  problem50.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/27.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem50.h"

//输入: 2.00000, -2
//输出: 0.25000
//解释: 2-2 = 1/22 = 1/4 = 0.25
//说明:
//
//-100.0 < x < 100.0
//n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    } else if (n == 1) {
        return x;
    } else if (n == -1) {
        return 1.0/x;
    }
    double half = myPow(x, n/2);
    if (n % 2 != 0) {
        return half * half * ((n < 0) ? 1.0/x : x);
    } else {
        return half * half;
    }
}
