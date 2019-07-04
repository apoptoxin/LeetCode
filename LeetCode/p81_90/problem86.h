//
//  problem86.h
//  LeetCode
//
//  Created by liunan on 2019/7/1.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef problem86_h
#define problem86_h

#include <stdio.h>
#include "node.h"
#endif /* problem86_h */

//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//
//你应当保留两个分区中每个节点的初始相对位置。
//
//示例:
//
//输入: head = 1->4->3->2->5->2, x = 3
//输出: 1->2->2->4->3->5

struct ListNode* partition(struct ListNode* head, int x);
