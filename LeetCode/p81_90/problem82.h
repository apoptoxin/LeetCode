//
//  problem82.h
//  LeetCode
//
//  Created by liunan on 2019/6/24.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef problem82_h
#define problem82_h

#include <stdio.h>
#include "node.h"
#endif /* problem82_h */

//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
//
//示例 1:
//
//输入: 1->2->3->3->4->4->5
//输出: 1->2->5
//示例 2:
//
//输入: 1->1->1->2->3
//输出: 2->3

struct ListNode* deleteDuplicates82(struct ListNode* head);