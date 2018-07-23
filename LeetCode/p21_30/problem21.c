//
//  problem21.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/23.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem21.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode *cur = NULL;
    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            //进入循环条件是l1 或者 l2至少有一个不为空，所以l1为空的话l2一定不为空
            if (head == NULL) {
                head = cur = l2;
            } else {
                cur->next = l2;
                cur = cur->next;
            }
            l2 = l2->next;
        } else if (l2 == NULL) {
            if (head == NULL) {
                head = cur = l1;
            } else {
                cur->next = l1;
                cur = cur->next;
            }
            l1 = l1->next;
        } else {
            if (l1->val < l2->val) {
                if (head == NULL) {
                    head = cur = l1;
                } else {
                    cur->next = l1;
                    cur = cur->next;
                }
                l1 = l1->next;
            } else {
                if (head == NULL) {
                    head = cur = l2;
                } else {
                    cur->next = l2;
                    cur = cur->next;
                }
                l2 = l2->next;
            }
        }
    }
    return head;
}
