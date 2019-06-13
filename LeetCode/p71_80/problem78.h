//
//  problem78.h
//  LeetCode
//
//  Created by liunan on 2019/6/13.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef problem78_h
#define problem78_h

#include <stdio.h>

#endif /* problem78_h */


//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
//说明：解集不能包含重复的子集。
//
//示例:
//
//输入: nums = [1,2,3]
//输出:
//[
// [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
