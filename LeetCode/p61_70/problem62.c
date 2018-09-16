//
//  problem62.c
//  LeetCode
//
//  Created by apoptoxin on 2018/9/16.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem62.h"

int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) {
        return 1;
    }
    int tmp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                tmp[i][j] = 1;
            } else {
                tmp[i][j] = tmp[i-1][j] + tmp[i][j-1];
            }
        }
    }
    
    return tmp[m-1][n-1];
}
