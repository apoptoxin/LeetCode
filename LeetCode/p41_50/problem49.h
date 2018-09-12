//
//  problem49.h
//  LeetCode
//
//  Created by apoptoxin on 2018/8/27.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem49_h
#define problem49_h

#include <stdio.h>

#endif /* problem49_h */

//字母异位词分组
//
//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
//示例:
//
//输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
//输出:
//[
// ["ate","eat","tea"],
// ["nat","tan"],
// ["bat"]
// ]
//说明：
//
//所有输入均为小写字母。
//不考虑答案输出的顺序。

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize);
