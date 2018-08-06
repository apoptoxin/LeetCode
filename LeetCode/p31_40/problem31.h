//
//  problem31.h
//  LeetCode
//
//  Created by 刘楠 on 2018/8/5.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem31_h
#define problem31_h

#include <stdio.h>

#endif /* problem31_h */

//下一个排列
//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//
//如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//
//必须原地修改，只允许使用额外常数空间。
//
//以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1

void nextPermutation(int* nums, int numsSize);
