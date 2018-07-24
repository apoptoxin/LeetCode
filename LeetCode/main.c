//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem25.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode l1 = {5,NULL};
    struct ListNode l2 = {4,&l1};
    struct ListNode l3 = {3,&l2};
    struct ListNode l4 = {2,&l3};
    struct ListNode l5 = {1,&l4};
    
    for (struct ListNode* i = &l5; i != NULL; i=i->next) {
        printf("%d->", i->val);
    }
    printf("\n");
    struct ListNode *r = reverseKGroup(&l5, 3);

    for (struct ListNode* i = r; i != NULL; i=i->next) {
        printf("%d->", i->val);
    }
//    printf("%d\n",isValid(s));
    
    return 0;
}
