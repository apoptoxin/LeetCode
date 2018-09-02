//
//  problem52.c
//  LeetCode
//
//  Created by apoptoxin on 2018/9/2.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem52.h"
#include "problem51.h"

int totalNQueens(int n) {
    int size = 0;
    solveNQueens(4, &size);
    return size;
}
