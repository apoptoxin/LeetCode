//
//  problem41.c
//  LeetCode
//
//  Created by apoptoxin on 2018/8/15.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem41.h"
#include "swap.h"

int firstMissingPositive(int* nums, int numsSize) {
    //核心思路就是把值为v的元素放到v-1的位置（v=nums[i]），这样，再次遍历数据，i与num[i]不相等的就是我们要找的了
    for (int i = 0; i < numsSize; ) {
        if (nums[i] > 0 && i != nums[i] - 1 && nums[i] - 1 < numsSize && nums[i] - 1 != nums[nums[i] - 1] - 1) {
            swapTwoInts(nums+i, nums+nums[i]-1);
        } else {
            i++;
        }
    }
    for (int i = 0 ; i < numsSize ; i++) {
        if (nums[i] - 1 != i) {
            return i+1;
        }
    }
    return numsSize < 1 ? 1 : nums[numsSize-1] + 1;
}
