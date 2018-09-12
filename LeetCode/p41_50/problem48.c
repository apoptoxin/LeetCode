//
//  problem48.c
//  LeetCode
//
//  Created by apoptoxin on 2018/8/27.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem48.h"

//n*n 矩阵要matrixColSizes有什么用？

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    //step 1 横向交换，每行第i和和倒数第i个交换
    for (int i = 0 ; i < matrixRowSize ; i++) {
        for (int j = 0 ; j < matrixRowSize && j < matrixRowSize - 1 - j; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixRowSize-1-j];
            matrix[i][matrixRowSize-1-j] = tmp;
        }
    }
    //step 2 对角线交换，以左下到右上为轴交换
    for (int i = 0 ; i < matrixRowSize; i++) {
        for (int j = 0 ; j < matrixRowSize && i + j < matrixRowSize-1; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixRowSize-1-j][matrixRowSize-1-i];
            matrix[matrixRowSize-1-j][matrixRowSize-1-i] = tmp;
        }
    }
}
