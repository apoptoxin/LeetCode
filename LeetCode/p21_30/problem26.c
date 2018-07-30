//
//  problem26.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/30.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem26.h"

int removeDuplicates(int* nums, int numsSize) {
    int total = 0;
    int cur = -1;
    for (int i = 0 ; i < numsSize; i++) {
        if (cur < 0 || nums[i] != nums[cur]) {
            nums[++cur] = nums[i];
            total++;
        }
    }
    return total;
}
