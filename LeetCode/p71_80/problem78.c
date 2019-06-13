//
//  problem78.c
//  LeetCode
//
//  Created by liunan on 2019/6/13.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem78.h"

int** subsetWithCur(int n, int* origin, int* returnSize, int** returnColumnSizes, int curCount, int *curAry) {
    printf("当前n=%d,curCount=%d\n",n,curCount);
    if (n <= 0) {
        int **re = malloc(sizeof(int *));
        int *ary = malloc(sizeof(int)*curCount);
        for (int i = 0 ; i < curCount; i++) {
            ary[i] = curAry[curCount - i - 1];
        }
        re[0] = ary;
        if (returnSize != NULL) {
            *returnSize = 1;
        }
        if (returnColumnSizes != NULL) {
            *returnColumnSizes = malloc(sizeof(int));
            (*returnColumnSizes)[0] = curCount;
        }
        printf("取到了：[");
        for (int i = 0; i < curCount; i++) {
            printf("%d, ",ary[i]);
        }
        printf("]\n");
        return re;
    }
    
    int count1 = 0;
    int *count1Col = NULL;
    int **count1Ary = subsetWithCur(n-1, origin, &count1, &count1Col, curCount, curAry);
    curCount++;
    curAry[curCount-1] = origin[n-1];
    printf("将origin中的%d位置值为%d放在curAry的%d位置\n",n-1,origin[n-1],curAry[curCount-1]);
    int count2 = 0;
    int *count2Col = NULL;
    int **count2Ary = subsetWithCur(n-1, origin, &count2, &count2Col, curCount, curAry);
    curAry[curCount-1] = 0;
    curCount--;
    //合并
    int total = count1 + count2;
    if (returnSize != NULL) {
        *returnSize = total;
    }
    if (returnColumnSizes != NULL) {
        *returnColumnSizes = malloc(sizeof(int)*total);
        for (int i = 0 ; i < total; i++) {
            if (i<count1) {
                (*returnColumnSizes)[i] = count1Col[i];
            } else {
                (*returnColumnSizes)[i] = count2Col[i-count1];
            }
        }
    }
    int **result = malloc(sizeof(int *)*total);
    for (int i = 0 ; i < total; i++) {
        if (i<count1) {
            result[i] = count1Ary[i];
        } else {
            result[i] = count2Ary[i-count1];
        }
    }
    return result;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    int *t = calloc(numsSize, sizeof(int));
    return subsetWithCur(numsSize, nums, returnSize, returnColumnSizes, 0, t);
}
