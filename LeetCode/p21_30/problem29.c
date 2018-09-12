//
//  problem29.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/30.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem29.h"

int curDivide(int *dividend, int divisor,int times) {
    if (*dividend == 0) {
        return 0;
    } else if (*dividend > 0) {
        *dividend = 0-*dividend;
        return -curDivide(dividend, divisor, times);
    } else if (divisor > 0) {
        return -curDivide(dividend, -divisor, times);
    }
    
    //这里就都变成负数了
    int ori = *dividend;
    if (ori > divisor) {
        return 0;
    } else if (ori-divisor<=divisor) {
        int step1 = curDivide(dividend, divisor+divisor, times+times);
        int step2 = curDivide(dividend, divisor, times);
        return step1+step2;
    } else {
        *dividend = ori-divisor;
        return times;
    }
}

int divide(int dividend, int divisor) {
    
    int ori = dividend;
    //    本题中，如果除法结果溢出，则返回 231 − 1;这里只有dividend为最小值，divisor=-1时才可能
    if (ori == -2147483648 && divisor == -1) {
        return 2147483647;
    }
    return curDivide(&ori, divisor, 1);
}
