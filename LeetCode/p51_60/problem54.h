//
//  problem54.h
//  LeetCode
//
//  Created by apoptoxin on 2018/9/3.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem54_h
#define problem54_h

#include <stdio.h>

#endif /* problem54_h */

//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
//
//示例 1:
//
//输入:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
// ]
//输出: [1,2,3,6,9,8,7,4,5]
//示例 2:
//
//输入:
//[
// [1, 2, 3, 4],
// [5, 6, 7, 8],
// [9,10,11,12]
// ]
//输出: [1,2,3,4,8,12,11,10,9,5,6,7]

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize);
