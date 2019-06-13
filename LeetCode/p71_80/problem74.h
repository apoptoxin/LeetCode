//
//  problem74.h
//  LeetCode
//
//  Created by liunan on 2019/6/2.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef problem74_h
#define problem74_h

#include <stdio.h>
#include "bool_define.h"

#endif /* problem74_h */

//编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
//
//每行中的整数从左到右按升序排列。
//每行的第一个整数大于前一行的最后一个整数。

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target);
