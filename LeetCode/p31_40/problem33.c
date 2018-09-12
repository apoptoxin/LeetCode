//
//  problem33.c
//  LeetCode
//
//  Created by apoptoxin on 2018/8/6.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem33.h"

int searchFromNums(int* nums, int start, int end, int target) {
    if (start >= end) {
        if (start > end) {
            return -1;
        } else {
            return nums[start] == target ? start : -1;
        }
    }
    //这里start最多等于mid,mid一定小于end
    int mid = ( start + end ) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if(start == mid) {
        return searchFromNums(nums, mid+1, end, target);
    } else {
        if (nums[mid] > nums[start]) {
            //旋转点在mid~end
            if (nums[mid] < target) {
                return searchFromNums(nums, mid+1, end, target);
            } else {
                int pos = searchFromNums(nums, start, mid-1, target);
                if (pos >= 0) {
                    return pos;
                } else {
                    return searchFromNums(nums, mid+1, end, target);
                }
            }
        } else {
            //旋转点在start ~ mid
            if (nums[mid] > target) {
                return searchFromNums(nums, start, mid-1, target);
            } else {
                int pos = searchFromNums(nums, start, mid-1, target);
                if (pos >= 0) {
                    return pos;
                } else {
                    return searchFromNums(nums, mid+1, end, target);
                }
            }
        }
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    return searchFromNums(nums, 0, numsSize-1, target);
}
