//
//  problem83.c
//  LeetCode
//
//  Created by liunan on 2019/6/25.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem83.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* result = NULL;
    struct ListNode* cur = NULL;
    while (head != NULL) {
        if (cur == NULL) {
            cur = head;
            result = head;
        } else if (head->val != cur->val) {
            cur->next = head;
            cur = head;
        }
        head = head->next;
    }
    if (cur != NULL) {
        cur->next = head;
    }
    return result;
}
