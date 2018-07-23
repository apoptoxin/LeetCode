//
//  problem23.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/23.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem23.h"
#include "bool_define.h"

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *head = NULL;
    struct ListNode *cur = NULL;
    bool stop = false;
    while (!stop) {
        //找最小的
        struct ListNode *little = NULL;
        bool allEmpty = true;
        int littleIndex = 0;
        for (int i = 0 ; i < listsSize; i++) {
            allEmpty = allEmpty && lists[i] == NULL;
            if (little == NULL) {
                little = lists[i];
                littleIndex = i;
            } else if (lists[i] != NULL) {
                if (little->val > lists[i]->val) {
                    little = lists[i];
                    littleIndex = i;
                }
            }
        }
        if (little != NULL) {
            if (head == NULL) {
                head = little;
                cur = little;
            } else {
                cur->next = little;
                cur = cur->next;
            }
            lists[littleIndex] = lists[littleIndex]->next;
        }
        stop = allEmpty;
    }
    return head;
}
