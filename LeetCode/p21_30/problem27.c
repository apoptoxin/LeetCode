//
//  problem27.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/30.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem27.h"

int removeElement(int* nums, int numsSize, int val) {
    int total = 0;
    int cur = -1;
    for (int i = 0 ; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[++cur] = nums[i];
            total++;
        }
    }
    return total;
}
