//
//  main.c
//  LeetCode
//
//  Created by apoptoxin on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem64.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int p[2][3] = {{1,2,5},{3,2,1}};
    int ** a = malloc(sizeof(int *) *2);
    for (int i = 0; i < 2; i++) {
        a[i] = malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++) {
            a[i][j] = 0;
        }
    }
    int r = minPathSum(a,2,3);
    return 0;
}
