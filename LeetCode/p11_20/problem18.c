//
//  problem18.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/16.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem18.h"
#include "sort.h"

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    quickSort(nums, numsSize);
    int total = 0;
    int** result = NULL;
    for (int k = 0 ; k < numsSize - 3 ; k++) {
        if(k>0 && nums[k]==nums[k-1])continue;
        for (int i = k+1 ; i < numsSize - 2; i++) {
            if(i>k+1 && nums[i]==nums[i-1])continue;
            //固定最小元素位置，在后面找两个元素和为-nums[i]的
            for (int j = i+1, end = numsSize-1 ; j < end ;) {
                //以i, j, end 这3个元素判断是否满足条件；
                int cal = nums[k] + nums[i] + nums[j] + nums[end];
                if (cal == target) {
                    
                    int* curPtr = (int*)malloc(sizeof(int) * 4);
                    curPtr[0] = nums[k];
                    curPtr[1] = nums[i];
                    curPtr[2] = nums[j];
                    curPtr[3] = nums[end];
                    if (total == 0) {
                        result = (int**)malloc(sizeof(int*));
                    } else {
                        result = (int**)realloc(result,(total+1)*sizeof(int*));
                    }
                    result[total] = curPtr;
                    total++;
                    do{++j;} while (end > j && nums[j] == nums[j-1]);
                } else if (cal > target) {
                    do{--end;} while (end > j && nums[end+1] == nums[end]);
                } else {
                    do{j++;} while (end > j && nums[j] == nums[j-1]);
                }
            }
        }
    }
    *returnSize = total;
    return result;
}
