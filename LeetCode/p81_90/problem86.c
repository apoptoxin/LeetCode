//
//  problem86.c
//  LeetCode
//
//  Created by liunan on 2019/7/1.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem86.h"

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* left = NULL;
    struct ListNode* right = NULL;
    struct ListNode* leftTmp = NULL;
    struct ListNode* rightTmp = NULL;
    while (head != NULL) {
        if (head->val < x) {
            if (left == NULL) {
                left = head;
                leftTmp = head;
            } else {
                leftTmp->next = head;
                leftTmp = head;
            }
        } else {
            if (right == NULL) {
                right = head;
                rightTmp = head;
            } else {
                rightTmp->next = head;
                rightTmp = head;
            }
        }
        head = head->next;
    }
    if (right != NULL) {
        rightTmp->next = NULL;
    }
    if (left == NULL) {
        left = right;
    } else {
        leftTmp->next = right;
    }
    return left;
}
