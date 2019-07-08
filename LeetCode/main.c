//
//  main.c
//  LeetCode
//
//  Created by apoptoxin on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem90.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int cur[] = {1,2,2};
    int *a = malloc(sizeof(int) * 3);
    for (int i = 0; i < 3 ; i++) {
        a[i] = cur[i];
    }
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **re = subsetsWithDup(a, 3, &returnSize, &returnColumnSizes);
    for (int i = 0 ; i < returnSize; i++) {
        printf("[");
        for (int j = 0 ; j < returnColumnSizes[i]; j++) {
            printf("%d",re[i][j]);
            if (j!=returnColumnSizes[i]-1) {
                printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}
