//
//  problem25.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem25.h"

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *newHead = NULL;
    struct ListNode *trim = NULL;//指向first的上一个
    struct ListNode *first = NULL;
    struct ListNode *end = NULL;
    struct ListNode *tmps = NULL;//临时指针,start
    struct ListNode *tmpe = NULL;//临时指针,end
    struct ListNode *tmp = NULL;
    while (head != NULL) {
        first = head;
        int i = 0;
        for (; i < k && head != NULL; i++) {
            end = head;
            head = head->next;
        }
        if (i < k) {
            if (trim == NULL) {
                newHead = first;
            }
            break;
        }
        //这里first指向要交换的第一个，end指向最后一个,head指向end的下一个
        tmps = first;
        tmpe = first->next;
        tmp = NULL;
        first->next = NULL;
        while (tmps!=end && tmpe!=NULL) {
            tmps->next = tmp;
            tmp = tmps;
            tmps = tmpe;
            tmpe = tmpe->next;
        }
        if (tmps == end) {
            tmps->next = tmp;
        }
        if (trim == NULL) {
            trim = first;
            newHead = end;
        } else {
            trim->next = end;
            trim = first;
        }
        first->next = head;
    }
    return newHead;
}
