//
//  problem47.c
//  LeetCode
//
//  Created by apoptoxin on 2018/8/27.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem47.h"
#include <stdlib.h>
#include "bool_define.h"

int cmpfunc47 (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

bool findItemInArray(int *nums,int size, int start, int end, int target) {
    //从start到end找值为target
    //可以用二分，懒得写，就遍历了
    for (int i = start ; i <= end; i++) {
        if (nums[i] == target) {
            return true;
        }
    }
    return false;
}

void constructSingleWithoutRepeat(int* nums, int numsSize, int** result, int *posToSave, int axis) {
    if (axis >= numsSize - 1) {
        int *tmp = malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            tmp[i] = nums[i];
            //            printf("%d ",tmp[i]);
        }
        //        printf("\n------------------\n");
        result[*posToSave] = tmp;
        *posToSave = (*posToSave)+1;
    }
    
    //axis及之前的都固定，交换后面的
    int lastChange = nums[axis+1];
    for (int i = axis + 1; i < numsSize ; i++) {
        //这里不是lastChange, 应该是在所有换过的里面找吧，所以也就是在axis+1到i-1的位置找i
//        nums[i] == lastChange
        if (i != axis+1 && (nums[i] == nums[axis+1] || findItemInArray(nums, numsSize, axis+1, i-1, nums[i]))) {
            continue;
        }
        lastChange = nums[i];
        //交换axis+1和i
        int tmp = nums[axis+1];
        nums[axis+1] = nums[i];
        nums[i] = tmp;
        //继续
        constructSingleWithoutRepeat(nums, numsSize, result, posToSave, axis+1);
        //换回来
        nums[i] = nums[axis+1];
        nums[axis+1] = tmp;
        
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    int count = 1;
    for (int i = 1 ; i <= numsSize; i++) {
        count = count * i;
    }
    //sort
    qsort(nums, numsSize, sizeof(int), cmpfunc47);
    int ** re = malloc(sizeof(int *) *count);
    int pos = 0;
    constructSingleWithoutRepeat(nums, numsSize, re, &pos, -1);
    if (returnSize) {
        *returnSize = pos;
    }
    return re;
}
