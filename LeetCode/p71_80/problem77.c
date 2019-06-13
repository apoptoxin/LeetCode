//
//  problem77.c
//  LeetCode
//
//  Created by liunan on 2019/6/3.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem77.h"
#include <stdlib.h>
int** combineWithCur(int n, int k, int* returnSize, int** returnColumnSizes, int curCount, int *curAry) {
    printf("当前n=%d,k=%d,curCount=%d\n",n,k,curCount);
    int needFetchCount = k - curCount;
    if (n < 0 || k <= 0 || needFetchCount < 0 || n < needFetchCount) {
        *returnSize = 0;
        return NULL;
    }
    
    if (needFetchCount == 0 || n == needFetchCount) {
        //全取，返回
        int **re = malloc(sizeof(int *));
        int *ary = malloc(sizeof(int)*k);
        for (int i = k-1 ; i >= 0; i--) {
            if (k-1-i < curCount) {
                ary[i] = curAry[i];
            } else {
                ary[i] = i+1;
            }
        }
        re[0] = ary;
        if (returnSize != NULL) {
            *returnSize = 1;
        }
        if (returnColumnSizes != NULL) {
            *returnColumnSizes = malloc(sizeof(int));
            (*returnColumnSizes)[0] = k;
        }
        printf("取到了：");
        for (int i = 0; i < k; i++) {
            printf("%d ",ary[i]);
        }
        printf("\n");
        return re;
    }
    
    int count1 = 0;
    int *count1Col = NULL;
    int **count1Ary = combineWithCur(n-1, k, &count1, &count1Col, curCount, curAry);
    curCount++;
    printf("k-curCount:%d\n",k-curCount);
    curAry[k-curCount] = n;
    int count2 = 0;
    int *count2Col = NULL;
    int **count2Ary = combineWithCur(n-1, k, &count2, &count2Col, curCount, curAry);
    curAry[k-curCount] = 0;
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

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    if (n <= 0 || k <= 0 || n < k) {
        *returnSize = 0;
        return NULL;
    }
    int *t = calloc(k, sizeof(int));
    return combineWithCur(n, k, returnSize, returnColumnSizes, 0, t);
}
