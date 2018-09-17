//
//  problem64.c
//  LeetCode
//
//  Created by 刘楠 on 2018/9/17.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem64.h"

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    for (int i = 0 ; i < gridRowSize ; i++) {
        for (int j = 0 ; j < gridColSize ; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                //j>0
                grid[i][j] = grid[i][j-1] + grid[i][j];
            } else if (j == 0) {
                //i>0
                grid[i][j] = grid[i-1][j] + grid[i][j];
            } else {
                int min = grid[i][j-1] < grid[i-1][j] ? grid[i][j-1] : grid[i-1][j];
                grid[i][j] = min + grid[i][j];
            }
        }
    }
    return grid[gridRowSize-1][gridColSize-1];
}
