//
//  problem15.h
//  LeetCode
//
//  Created by 刘楠 on 2018/7/11.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem15_h
#define problem15_h

#include <stdio.h>

#endif /* problem15_h */

//三数之和
//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
//例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
// [-1, 0, 1],
// [-1, -1, 2]
// ]

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize);
