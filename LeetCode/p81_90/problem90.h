//
//  problem90.h
//  LeetCode
//
//  Created by liunan on 2019/7/8.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef problem90_h
#define problem90_h

#include <stdio.h>

#endif /* problem90_h */

//给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
//说明：解集不能包含重复的子集。
//
//示例:
//
//输入: [1,2,2]
//输出:
//[
// [2],
// [1],
// [1,2,2],
// [2,2],
// [1,2],
// []
// ]

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
