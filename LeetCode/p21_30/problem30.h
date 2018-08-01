//
//  problem30.h
//  LeetCode
//
//  Created by 刘楠 on 2018/7/31.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem30_h
#define problem30_h

#include <stdio.h>

#endif /* problem30_h */

//与所有单词相关联的字串
//给定一个字符串 s 和一些长度相同的单词 words。在 s 中找出可以恰好串联 words 中所有单词的子串的起始位置。
//
//注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
//
//示例 1:
//
//输入:
//s = "barfoothefoobarman",
//words = ["foo","bar"]
//输出: [0,9]
//解释: 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
//输出的顺序不重要, [9,0] 也是有效答案。
//示例 2:
//
//输入:
//s = "wordgoodstudentgoodword",
//words = ["word","student"]
//输出: []

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize);
