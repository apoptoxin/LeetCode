//
//  problem53.c
//  LeetCode
//
//  Created by apoptoxin on 2018/9/2.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem53.h"

int maxSubArray(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    int cur = nums[0];
    int max = nums[0];
    for (int i = 0 ; i < numsSize ; i++) {
        cur = (i > 0 && cur > 0) ? cur + nums[i] : nums[i];
        max = cur > max ? cur : max;
    }
    return max;
}

#pragma undo - 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
