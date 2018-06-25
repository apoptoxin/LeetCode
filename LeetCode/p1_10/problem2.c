//
//  problem2.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/25.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem2.h"
#include <stdlib.h>

struct ListNode* addTwoNumberWithAddition(struct ListNode *l1, struct ListNode *l2,int addition)
{
    if (l1 == NULL && l2 == NULL && addition == 0) {
        return NULL;
    }
    //cal current
    struct ListNode* cur = malloc(sizeof(struct ListNode));
    int l1Val = (l1 == NULL) ? 0 : l1->val;
    int l2Val = (l2 == NULL) ? 0 : l2->val;
    int total = l1Val + l2Val + addition;
    cur->val = total % 10;
    cur->next = addTwoNumberWithAddition(l1 == NULL?NULL:l1->next, l2 == NULL ? NULL : l2->next, total / 10);
    return cur;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addTwoNumberWithAddition(l1, l2, 0);
}
