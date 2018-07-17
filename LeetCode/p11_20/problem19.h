//
//  problem19.h
//  LeetCode
//
//  Created by 刘楠 on 2018/7/17.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem19_h
#define problem19_h

#include <stdio.h>

#endif /* problem19_h */

struct ListNode {
    int val;
    struct ListNode *next;
};
//删除链表的倒数第N个节点
//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//
//示例：
//
//给定一个链表: 1->2->3->4->5, 和 n = 2.
//
//当删除了倒数第二个节点后，链表变为 1->2->3->5.
//说明：
//
//给定的 n 保证是有效的。
//
//进阶：
//
//你能尝试使用一趟扫描实现吗？

struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
