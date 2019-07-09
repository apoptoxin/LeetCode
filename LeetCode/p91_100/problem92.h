//
//  problem92.h
//  LeetCode
//
//  Created by liunan on 2019/7/9.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef problem92_h
#define problem92_h

#include <stdio.h>
#include "node.h"

#endif /* problem92_h */


//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
//
//说明:
//1 ≤ m ≤ n ≤ 链表长度。
//
//示例:
//
//输入: 1->2->3->4->5->NULL, m = 2, n = 4
//输出: 1->4->3->2->5->NULL

struct ListNode* reverseBetween(struct ListNode* head, int m, int n);
