//
//  problem6.h
//  LeetCode
//
//  Created by apoptoxin on 2018/7/1.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem6_h
#define problem6_h

#include <stdio.h>

#endif /* problem6_h */

//将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"
//
//实现一个将字符串进行指定行数变换的函数:
//
//string convert(string s, int numRows);
//示例 1:
//
//输入: s = "PAYPALISHIRING", numRows = 3
//输出: "PAHNAPLSIIGYIR"
//示例 2:
//
//输入: s = "PAYPALISHIRING", numRows = 4
//输出: "PINALSIGYAHRPI"
//解释:
//
//P     I    N
//A   L S  I G
//Y A   H R
//P     I

char* convert(char* s, int numRows);
