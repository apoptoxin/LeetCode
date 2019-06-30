//
//  problem82.c
//  LeetCode
//
//  Created by liunan on 2019/6/24.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem82.h"

struct ListNode* deleteDuplicates82(struct ListNode* head){
    struct ListNode* result = NULL;
    struct ListNode* pre = NULL;
    struct ListNode* cur = NULL;
    struct ListNode* axe = NULL;
    while (head != NULL) {
        if (cur == NULL) {
            cur = head;
            result = head;
            axe = cur;
        } else if (head->val == cur->val) {
            axe = pre;
        } else {
            //head->val != cur->val
            if (axe == NULL) {
                cur = head;
                result = head;
                axe = cur;
            } else {
                axe->next = head;
                pre = axe;
                cur = head;
                axe = axe->next;
            }
        }
        head = head->next;
    }
    if (axe == NULL) {
        result = NULL;
    } else {
        axe->next = NULL;
    }
    return result;
}
