//
//  problem37.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/9.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem37.h"
#include "bool_define.h"

static int v[9] = {1<<1,1<<2,1<<3,1<<4,1<<5,1<<6,1<<7,1<<8,1<<9};

bool isValidSudokuWithChecker(char **board, int *rowCheck, int *colCheck, int *recCheck, int index) {
    if (index >= 81) {
        return true;
    }
    int row = index / 9;
    int col = index % 9;
    int rec = (row/3)*3+(col/3);
    char c = board[row][col];
    if (c == '.') {
        for (int i = 0 ; i < 9; i++) {
            if ((rowCheck[row] & v[i]) > 0 || (colCheck[col] & v[i]) > 0 || (recCheck[rec] & v[i]) > 0) {
                //有这个元素
                continue;
            } else {
                rowCheck[row] |= v[i];
                colCheck[col] |= v[i];
                recCheck[rec] |= v[i];
                board[row][col] = '0'+(i+1);
                //先赋值，然后深度遍历
                bool res = isValidSudokuWithChecker(board, rowCheck, colCheck, recCheck, index+1);
                if (res) {
                    return res;
                }
                //不可行之后需要恢复
                board[row][col] = '.';
                rowCheck[row] ^= v[i];
                colCheck[col] ^= v[i];
                recCheck[rec] ^= v[i];
            }
        }
        return false;
    } else {
        return isValidSudokuWithChecker(board,rowCheck,colCheck,recCheck,index+1);
    }
    return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    if (boardColSize != 9 || boardRowSize != 9) {
        return;
    }
    int *col = calloc(9,sizeof(int)); //表示第i行的值
    int *row = calloc(9,sizeof(int)); //表示第i列的值
    int *rec = calloc(9,sizeof(int)); //rec表示3*3的方格，下标=行下标/3*3+列下标/3
    for (int i = 0 ; i < 9 && i < boardRowSize; i++) {
        for (int j = 0 ; j < 9 && j < boardColSize; j++) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            }
            int t = v[c-'0'-1];
            int ri = (i/3)*3+(j/3);
            row[i] |= t;
            col[j] |= t;
            rec[ri] |= t;
        }
    }
    isValidSudokuWithChecker(board, row, col, rec, 0);
}
