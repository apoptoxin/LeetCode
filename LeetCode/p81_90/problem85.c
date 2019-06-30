//
//  problem85.c
//  LeetCode
//
//  Created by liunan on 2019/6/26.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem85.h"
#include "problem84.h"

//一行一行累加计算
//比如
//[
// ["1","0","1","0","0"],
// ["1","0","1","1","1"],
// ["1","1","1","1","1"],
// ["1","0","0","1","0"]
// ]
// 先算第一行，1，0，1，0，0
// 再算第二行，2，0，2，1，1 -》即在之前基础上，遇到1就加1，遇到0则等于0
// 再算第三行，3，1，3，2，2
// 再算第四行，4，0，0，3，0

// 每次计算时间复杂度为O(n)，需要计算m次，所以总时间复杂度为O(mn)，即O(n*n)

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize <= 0 || matrixColSize[0] <= 0) {
        return 0;
    }
    int max = 0;
    int row = matrixSize;
    int col = matrixColSize[0];
    int *hold = calloc(col, sizeof(int));
    for (int i = 0 ; i < row ; i++) {
        for (int j = 0 ; j < col; j++) {
            if (matrix[i][j] == '0') {
                hold[j] = 0;
            } else {
                hold[j] += 1;
            }
        }
        int tmp = largestRectangleArea(hold, col);
        max = max > tmp ? max : tmp;
    }
    return max;
}
