//
//  main.c
//  LeetCode
//
//  Created by apoptoxin on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem62.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int p[4][5] = {{0,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int ** a = malloc(sizeof(int *) *4);
    for (int i = 0; i < 4; i++) {
        a[i] = malloc(sizeof(int) * 5);
        for (int j = 0; j < 5; j++) {
            a[i][j] = 0;
        }
    }
    int r = uniquePathsWithObstacles(a,4, 5);
    return 0;
}
