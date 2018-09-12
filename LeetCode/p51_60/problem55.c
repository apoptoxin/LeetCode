//
//  problem55.c
//  LeetCode
//
//  Created by apoptoxin on 2018/9/3.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem55.h"

bool canJump(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return true;
    }
    int longest = nums[0];
    for (int i = 0 ; i < numsSize ; i++) {
        if (i <= longest) {
            longest = longest > nums[i]+i ? longest : nums[i]+i;
        }
    }
    return longest >= numsSize-1;
}
