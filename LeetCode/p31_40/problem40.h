//
//  problem40.h
//  LeetCode
//
//  Created by 刘楠 on 2018/8/14.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem40_h
#define problem40_h

#include <stdio.h>

#endif /* problem40_h */

//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的每个数字在每个组合中只能使用一次。
//
//说明：
//
//所有数字（包括目标数）都是正整数。
//解集不能包含重复的组合。
//示例 1:
//
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
// [1, 7],
// [1, 2, 5],
// [2, 6],
// [1, 1, 6]
// ]
//示例 2:
//
//输入: candidates = [2,5,2,1,2], target = 5,
//所求解集为:
//[
// [1,2,2],
// [5]
// ]

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize);
