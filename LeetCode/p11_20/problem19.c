//
//  problem19.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/17.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem19.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //当前指针
    struct ListNode *cur = head;
    //当前指针前面n个指针
    struct ListNode *cur_n = head;
    //当前指针前面n+1个指针
    struct ListNode *cur_np1 = head;
    int step = 0;
    while (cur != NULL) {
        if (step >= n-1) {
            //保持不动
            cur_np1 = cur_n;
        }
        if (step >= n) {
            cur_n = cur_n->next;
        }
        cur = cur->next;
        step++;
    }
    //需要去掉的是cur_n
    if (cur_n == head && cur_n != NULL) {
        head = head->next;
    } else if (cur_np1 != NULL && cur_n != NULL) {
        cur_np1->next = cur_n->next;
    }
    return head;
}
