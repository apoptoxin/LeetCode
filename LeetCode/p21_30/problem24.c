//
//  problem24.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem24.h"

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *trim = NULL;
    struct ListNode *newHead = NULL;
    struct ListNode *first = NULL;
    struct ListNode *second = NULL;
    while (head != NULL) {
        first = head;
        second = head->next;
        head = second;
        if (head!=NULL) {
            head = head->next;
            //这里head就应该指向second的下一个了
        }
        if (second == NULL) {
            //只有一个元素，不用交换
            if (newHead == NULL) {
                newHead = first;
            }
        } else {
            //交换first和second
            //当前trim应该指向NULL或者first的前两个
            second->next = first;
            first->next = head;
            if (trim == NULL) {
                trim = second;
                newHead = trim;
            } else {
                trim->next->next = second;
                trim = second;
            }
        }
    }
    return newHead;
}
