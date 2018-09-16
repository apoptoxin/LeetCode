//
//  problem63.c
//  LeetCode
//
//  Created by apoptoxin on 2018/9/16.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem63.h"

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if (obstacleGridRowSize == 0 && obstacleGridColSize == 0) {
        return 1;
    }
    int tmp[obstacleGridRowSize][obstacleGridColSize];
    for (int i = 0; i < obstacleGridRowSize; i++) {
        for (int j = 0; j < obstacleGridColSize; j++) {
            if (obstacleGrid[i][j] == 1) {
                tmp[i][j] = 0;
            } else if (i == 0 && j == 0) {
                tmp[i][j] = 1;
            } else if (i == 0 && j != 0) {
                tmp[i][j] = obstacleGrid[i][j-1] == 1 ? 0 : tmp[i][j-1];
            } else if (i != 0 && j == 0) {
                tmp[i][j] = obstacleGrid[i-1][j] == 1 ? 0 : tmp[i-1][j];
            } else {
                tmp[i][j] = 0;// tmp[i-1][j] + tmp[i][j-1];
                if (obstacleGrid[i][j-1] == 0) {
                    tmp[i][j] += tmp[i][j-1];
                }
                if (obstacleGrid[i-1][j] == 0) {
                    tmp[i][j] += tmp[i-1][j];
                }
            }
        }
    }
    return tmp[obstacleGridRowSize-1][obstacleGridColSize-1];
}
