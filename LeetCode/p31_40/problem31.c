//
//  problem31.c
//  LeetCode
//
//  Created by apoptoxin on 2018/8/5.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem31.h"
#include "sort.h"

void nextPermutation(int* nums, int numsSize) {
    if (numsSize < 2) {
        return;
    }
    int index = -1;
    //从前往后找到最后一个升序
    for (int i = 1 ; i < numsSize ; i++) {
        if (nums[i] > nums[i-1]) {
            index = i;
        }
    }
    if (index > 0) {
        //找到了升序，index 和 index-1。从index开始到numsSize-1中找比nums[index-1]大的数中的最小值
        int tmpIndex = index;
        for (int i = index; i<numsSize; i++) {
            if (nums[i] > nums[index-1] && nums[i] < nums[tmpIndex]) {
                tmpIndex = i;
            }
        }
        int temp = nums[index-1];
        nums[index-1] = nums[tmpIndex];
        nums[tmpIndex] = temp;
        //index到结尾 sort
        quickSort(nums+index, numsSize - index);
    } else {
        //全排列，逆序就可以
        quickSort(nums, numsSize);
    }
}
