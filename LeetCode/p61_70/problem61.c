//
//  problem61.c
//  LeetCode
//
//  Created by apoptoxin on 2018/9/16.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem61.h"

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *last = NULL;
    int total = 0;
    for (struct ListNode * h = head ; h != NULL ; h = h->next) {
        total ++;
        last = h;
    }
    int step = (total - k % total) % total;
    struct ListNode *prev = last;
    struct ListNode *newHead = head;
    for (int i = 0 ; i < step; i++) {
        prev = newHead;
        newHead = newHead->next;
    }
    last->next = head;
    prev->next = NULL;
    return newHead;
}
