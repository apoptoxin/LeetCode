//
//  problem23.h
//  LeetCode
//
//  Created by apoptoxin on 2018/7/23.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem23_h
#define problem23_h

#include <stdio.h>

#endif /* problem23_h */


//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//
//示例:
//
//输入:
//[
// 1->4->5,
// 1->3->4,
// 2->6
// ]
//输出: 1->1->2->3->4->4->5->6

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);
