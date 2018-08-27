//
//  problem46.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/20.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem46.h"
#include <stdlib.h>

void constructSingle(int* nums, int numsSize, int** result, int *posToSave, int axis) {
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
    for (int i = axis + 1; i < numsSize ; i++) {
        //交换axis+1和i
        int tmp = nums[axis+1];
        nums[axis+1] = nums[i];
        nums[i] = tmp;
        //继续
        constructSingle(nums, numsSize, result, posToSave, axis+1);
        //换回来
        nums[i] = nums[axis+1];
        nums[axis+1] = tmp;
        
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {
    int count = 1;
    for (int i = 1 ; i <= numsSize; i++) {
        count = count * i;
    }
    if (returnSize) {
        *returnSize = count;
    }
    int ** re = malloc(sizeof(int *) *count);
    int pos = 0;
    constructSingle(nums, numsSize, re, &pos, -1);
    return re;
}
