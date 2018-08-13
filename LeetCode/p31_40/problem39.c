//
//  problem39.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/13.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem39.h"
#include <stdlib.h>

int cmpfunc39 (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int total = 0;
    int **result;
    int *columnSize;
    int columnSizeCount = 0;
    int *tmp = malloc(sizeof(int) * target);//用于记录暂存的数值下标
    int pos = -1;
    qsort(candidates, candidatesSize, sizeof(int), cmpfunc39);
    int axis = candidatesSize-1;
    int curTarget = target;
    while (pos >= 0 || axis >= 0) {
        printf("tmp:");
        for (int i = 0 ; i <= pos ; i++) {
            printf("%d ",candidates[tmp[i]]);
        }
        printf("\r\npos:%d curAxisVal:%d curTar:%d\n\r",pos,candidates[axis],curTarget);
        ////////////////
        if (curTarget <= 0) {
            if (curTarget == 0) {
                int *out = malloc(sizeof(int) * (pos+1));
                for (int i = 0 ; i <= pos; i++) {
                    out[i] = candidates[tmp[i]];
                }
                if (total == 0) {
                    result = malloc(sizeof(int *));
                    
                    result[0] = out;
                } else {
                    result = realloc(result,sizeof(int*)*(total+1));
                    result[total] = out;
                }
                if (columnSizeCount == 0) {
                    columnSize = malloc(sizeof(int));
                } else {
                    columnSize = realloc(columnSize, sizeof(int) * (columnSizeCount+1));
                }
                columnSize[columnSizeCount] = pos + 1;
                columnSizeCount++;
                total++;
            }
            //回滚最后一位
            curTarget += candidates[tmp[pos]];
            axis = tmp[pos] - 1;
            pos--;
            while (axis < 0 && pos >= 0) {
                curTarget += candidates[tmp[pos]];
                axis = tmp[pos] - 1;
                pos--;
            }
        } else {
            tmp[++pos] = axis;
            curTarget -= candidates[axis];
        }
    }
    if (returnSize) {
        *returnSize = total;
    }
    if (columnSizes) {
        *columnSizes = columnSize;
    }
    return result;
}
