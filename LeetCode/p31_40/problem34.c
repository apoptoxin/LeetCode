//
//  problem34.c
//  LeetCode
//
//  Created by apoptoxin on 2018/8/6.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem34.h"
#include "bool_define.h"

int indexForTarget(int* nums, int start, int end, int target, bool left) {
    //left这个bool型表示的是向左找到底，false就是向右找到底
    if (start >= end) {
        return (start == end && nums[start] == target) ? start : -1;
    }
    int index = -1;
    int mid = (start + end) / 2;
    if (nums[mid] == target) {
        index = mid;
    }
    if (mid == start && nums[mid] == target) {
        if (left) {
            return index;
        } else {
            return nums[end] == target ? end : index;
        }
    } else {
        if ((left && nums[mid] == target) || nums[mid] > target) {
            int find = indexForTarget(nums, start, mid-1, target, left);
            return find >= 0 ? find : index;
        } else {
            int find = indexForTarget(nums, mid+1, end, target, left);
            return find >= 0 ? find : index;
        }
    }
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *re = malloc(sizeof(int) * 2);
    if (returnSize) {
        *returnSize = 2;
    }
    re[0] = indexForTarget(nums, 0, numsSize-1, target, true);
    re[1] = indexForTarget(nums, 0, numsSize-1, target, false);
    return re;
}
