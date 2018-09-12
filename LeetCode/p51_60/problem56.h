//
//  problem56.h
//  LeetCode
//
//  Created by apoptoxin on 2018/9/10.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem56_h
#define problem56_h

#include <stdio.h>

#endif /* problem56_h */

//合并区间
//给出一个区间的集合，请合并所有重叠的区间。
//
//示例 1:
//
//输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//示例 2:
//
//输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

struct Interval {
    int start;
    int end;
};

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize);
