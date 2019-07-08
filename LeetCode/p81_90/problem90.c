//
//  problem90.c
//  LeetCode
//
//  Created by liunan on 2019/7/8.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem90.h"
#include "sort.h"

void subsetsForProblem90(int *nums, int totalSize, int curPos, int* returnSize, int** returnColumnSizes, int ***returnSubsets,int *curValue, int curTmpLength);

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if (numsSize <= 0) {
        return NULL;
    }
    quickSort(nums, numsSize);
    int ***result = malloc(sizeof(int**));
    *result = NULL;
    int *tmpAry = malloc(sizeof(int) * numsSize);
    subsetsForProblem90(nums, numsSize, 0, returnSize, returnColumnSizes, result, tmpAry, 0);
    return *result;
}

void subsetsForProblem90(int *nums, int totalSize, int curPos, int* returnSize, int** returnColumnSizes, int ***returnSubsets, int *curValue, int curTmpLength) {
    if (curPos >= totalSize) {
        int *oneSubset = malloc(sizeof(int) * curTmpLength);
        for (int i = 0; i < curTmpLength ; i++) {
            oneSubset[i] = curValue[i];
        }
        if (*returnSubsets == NULL) {
            *returnSubsets = malloc(sizeof(int*));
            (*returnSubsets)[0] = oneSubset;
            *returnColumnSizes = malloc(sizeof(int));
            (*returnColumnSizes)[0] = curTmpLength;
            *returnSize = 1;
        } else {
            *returnSubsets = realloc(*returnSubsets, sizeof(int*) * (*returnSize + 1));
            (*returnSubsets)[*returnSize] = oneSubset;
            *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
            (*returnColumnSizes)[*returnSize] = curTmpLength;
            *returnSize = *returnSize + 1;
        }
        return;
    }
    //取当前，则递归下一个
    curValue[curTmpLength++] = nums[curPos];
    subsetsForProblem90(nums, totalSize, curPos+1, returnSize, returnColumnSizes, returnSubsets, curValue, curTmpLength);
    
    //不取当前，则找到下一个不同的，再递归
    curTmpLength--;
    int a = curPos + 1;
    while (a < totalSize) {
        if (nums[a] != nums[curPos]) {
            break;
        }
        a++;
    }
    subsetsForProblem90(nums, totalSize, a, returnSize, returnColumnSizes, returnSubsets, curValue, curTmpLength);
    
}
