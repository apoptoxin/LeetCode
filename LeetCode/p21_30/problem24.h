//
//  problem24.h
//  LeetCode
//
//  Created by apoptoxin on 2018/7/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#ifndef problem24_h
#define problem24_h

#include <stdio.h>

#endif /* problem24_h */

//两两交换链表中的节点
//
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
//示例:
//
//给定 1->2->3->4, 你应该返回 2->1->4->3.
//说明:
//
//你的算法只能使用常数的额外空间。
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。



struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head);
