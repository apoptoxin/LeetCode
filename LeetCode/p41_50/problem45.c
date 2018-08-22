//
//  problem45.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/20.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem45.h"

int jump(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }
    int *step = calloc(numsSize,sizeof(int));
    for (int i = 0 ; i < numsSize; i++) {
        for (int j = i+1; j - i <= nums[i] && j < numsSize ; j++) {
            int cur = step[i] + 1;
            if (step[j] == 0 || step[j] > cur) {
                step[j] = cur;
            }
        }
    }
    return step[numsSize-1];
}
