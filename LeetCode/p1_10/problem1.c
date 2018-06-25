//
//  problem1.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem1.h"
#include "sort.h"

int* twoSum(int* nums, int numsSize, int target) {
    int *result = (int *)malloc(sizeof(int) * 2);
    for (int i = 0 ; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums [j] == target) {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }
    return result;
}


