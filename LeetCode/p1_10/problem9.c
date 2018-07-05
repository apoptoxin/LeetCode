//
//  problem9.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/4.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem9.h"

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    } else if (x < 10) {
        return true;
    }
    int length = 0;
    int temp = x;
    while (temp != 0) {
        length ++;
        temp /= 10;
    }
    temp = 1;
    for (int i = 0; i < length / 2; i++) {
        temp *= 10;
    }
    int left = 1;
    int right = 1;
    if (length % 2 == 0) {
        left = x / temp;
        right = x % temp;
    } else {
        left = x / (temp*10);
        right = x % temp;
    }
    bool result = true;
    while (left != 0) {
        int leftSingle = left % 10;
        left = left / 10;
        temp /= 10;
        int rightSingle = right / temp;
        right = right % temp;
        result = result && leftSingle == rightSingle;
    }
    return result;
}
