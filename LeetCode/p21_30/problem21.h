//
//  problem21.h
//  LeetCode
//
//  Created by 刘楠 on 2018/7/23.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem21_h
#define problem21_h

#include <stdio.h>

#endif /* problem21_h */

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
