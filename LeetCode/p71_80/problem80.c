//
//  problem80.c
//  LeetCode
//
//  Created by liunan on 2019/6/18.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem80.h"

int removeDuplicates(int* nums, int numsSize) {
    int count = 0;
    int curIndex = -1;
    for (int i = 0 ; i < numsSize; i++) {
        if (curIndex < 0) {
            curIndex++;
            count = 1;
        } else if (nums[i] == nums[curIndex]) {
            if (count < 2) {
                count++;
                nums[++curIndex] = nums[i];
            }
        } else {
            count = 1;
            nums[++curIndex] = nums[i];
        }
    }
    return curIndex+1;
}
