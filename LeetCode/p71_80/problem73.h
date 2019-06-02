//
//  problem73.h
//  LeetCode
//
//  Created by liunan on 2019/5/29.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef problem73_h
#define problem73_h

#include <stdio.h>

#endif /* problem73_h */

//给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

//输入:
//[
// [1,1,1],
// [1,0,1],
// [1,1,1]
// ]
//输出:
//[
// [1,0,1],
// [0,0,0],
// [1,0,1]
// ]


//一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
void setZeroes(int** matrix, int matrixSize, int* matrixColSize);
