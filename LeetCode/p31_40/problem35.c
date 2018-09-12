//
//  problem35.c
//  LeetCode
//
//  Created by apoptoxin on 2018/8/6.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem35.h"

int searchInsertPosition(int *nums, int start, int end, int target) {
    if (start > end) {
        if (end >= 0 && nums[end] > target) {
            return end;
        } else {
            return start;
        }
    }
    int mid = (start + end) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] < target) {
        return searchInsertPosition(nums, mid+1, end, target);
    } else {
        return searchInsertPosition(nums, start, mid-1, target);
    }
}

int searchInsert(int* nums, int numsSize, int target) {
    return searchInsertPosition(nums, 0, numsSize-1, target);
}
