//
//  problem39.h
//  LeetCode
//
//  Created by 刘楠 on 2018/8/13.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem39_h
#define problem39_h

#include <stdio.h>

#endif /* problem39_h */

//组合总和
//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的数字可以无限制重复被选取。
//
//说明：
//
//所有数字（包括 target）都是正整数。
//解集不能包含重复的组合。
//示例 1:
//
//输入: candidates = [2,3,6,7], target = 7,
//所求解集为:
//[
// [7],
// [2,2,3]
// ]
//示例 2:
//
//输入: candidates = [2,3,5], target = 8,
//所求解集为:
//[
// [2,2,2,2],
// [2,3,3],
// [3,5]
// ]

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize);
