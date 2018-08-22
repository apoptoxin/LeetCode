//
//  problem46.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/20.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem46.h"
#include <stdlib.h>

int** permute(int* nums, int numsSize, int* returnSize) {
    int count = numsSize * numsSize;
    if (returnSize) {
        *returnSize = count;
    }
    int ** re = malloc(sizeof(int *) *count);
    int *tmp = malloc(sizeof(int) * numsSize);
    for (int i = 0 ; i < numsSize; i++) {
        tmp[i] = nums[i];
    }
    for (int i = 0 , pos = 0, cur = 0; i < count ; i++) {
        if (i == 0) {
            re[i] = tmp;
        } else {
            int *t = malloc(sizeof(int)*numsSize);
            memcpy(t,tmp,sizeof(int)*numsSize);
            if (cur < numsSize - 1) {
                int a = t[cur];
                t[cur] = t[cur+1];
                t[++cur] = a;
            } else {
                int a = t[pos];
                t[pos] = t[pos+1];
                t[++pos] = a;
                
                int last = t[numsSize-1];
                for (int k = numsSize-1; k > 0 ; k--) {
                    t[k] = t[k-1];
                }
                t[0] = last;
                cur = 0;
            }
            re[i] = t;
            tmp = t;
        }
        for (int p = 0 ; p < numsSize ; p++) {
            printf("%d ",re[i][p]);
        }
        printf("\n");
    }
    return re;
}
