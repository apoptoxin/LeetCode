//
//  problem92.c
//  LeetCode
//
//  Created by liunan on 2019/7/9.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem92.h"

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (m == n) {
        return head;
    }
    struct ListNode* result = head;
    struct ListNode* lastPre = NULL;
    struct ListNode* last = NULL;
    struct ListNode* first = NULL;
    struct ListNode* firstNext = NULL;
    for (int i = 0 ; i < m || i < n; i++) {
        if (i < m) {
            lastPre = last;
            if (last == NULL) {
                last = head;
            } else {
                last = last->next;
            }
        }
        if (first == NULL) {
            first = head;
        } else {
            first = first->next;
        }
    }
    firstNext = first->next;
    struct ListNode* tmpP = NULL;
    struct ListNode* tmpC = last;
    struct ListNode* tmpN = last->next;
    while (tmpC != firstNext) {
        tmpC->next = tmpP;
        tmpP = tmpC;
        tmpC = tmpN;
        if(tmpN != NULL) {
            tmpN = tmpN->next;
        }
    }
    if (lastPre != NULL) {
        lastPre->next = first;
    }
    last->next = firstNext;
    if (lastPre == NULL) {
        result = first;
    }
    return result;
}
