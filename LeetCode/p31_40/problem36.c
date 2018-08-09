//
//  problem36.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/9.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem36.h"


bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    //用位运算，假设第i行有5 那么 col[i] = col[i] | 1<<5;
    int col[9] = {0}; //表示第i行的值
    int row[9] = {0}; //表示第i列的值
    int rec[9] = {0}; //rec表示3*3的方格，下标=行下标/3*3+列下标/3
    for (int i = 0 ; i < 9 && i < boardRowSize; i++) {
        for (int j = 0 ; j < 9 && j < boardColSize; j++) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            }
            int t = 1 << (c-'0');
            int ri = (i/3)*3+(j/3);
            if ((row[i] & t) > 0) {
                return false;
            } else if ((col[j] & t) > 0) {
                return false;
            } else if ((rec[ri] & t) > 0) {
                return false;
            }
            row[i] |= t;
            col[j] |= t;
            rec[ri] |= t;
        }
    }
    return true;
}
