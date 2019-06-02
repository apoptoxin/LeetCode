//
//  problem73.c
//  LeetCode
//
//  Created by liunan on 2019/5/29.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem73.h"

// 遍历两次，时间复杂度为O(mn)
// 只用了一个变量a记录状态，空间复杂度为O(1)
// 用了数组中第0行第0列辅助记录状态。
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return;
    }
    int a = 0;//[0,0]状态，-1表示本身就为0，1 and 2表示最终结果为0，0表示保持不变。
    for (int i = 0 ; i < matrixSize ; i++) {
        int colSize = matrixColSize[i];
        for (int j = 0 ; j < colSize ; j++) {
            if (matrix[i][j] == 0) {
                if (i == 0 && j == 0) {
                    a = -1;
                } else if (i == 0 || j == 0) {
                    a = i == 0 ? a|1 : a|2; //a&1>0表示第0行上有0，a&2>0表示第0列上有0
                }
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (int i = matrixSize - 1 ; i >= 0 ; i--) {
        int colSize = matrixColSize[i];
        for (int j = colSize - 1 ; j >= 0 ; j--) {
            if (i == 0 || j == 0) {
                if (a == -1) {
                    matrix[i][j] = 0;
                } else if (i == 0 && (a & 1) > 0) {
                    matrix[i][j] = 0;
                } else if (j == 0 && (a & 2) > 0) {
                    matrix[i][j] = 0;
                }
            } else if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
}
