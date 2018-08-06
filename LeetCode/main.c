//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem35.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    struct ListNode l1 = {5,NULL};
//    struct ListNode l2 = {4,&l1};
//    struct ListNode l3 = {3,&l2};
//    struct ListNode l4 = {2,&l3};
//    struct ListNode l5 = {1,&l4};
    
//    for (struct ListNode* i = &l5; i != NULL; i=i->next) {
//        printf("%d->", i->val);
//    }
//    printf("\n");
    int a[] = {1,3,5,6};
//    int length = removeElement(a, 4, 3);
//    for (int i = 0 ; i<length; i++) {
//        printf("%d ",a[i]);
//    }
//    char *s = "barfoothefoobarman";
//    char **word = malloc(sizeof(char * )*0);
//    word[0] = "foo";
//    word[1] = "bar";
//    int returnSize = 0;
    printf("%d\n",searchInsert(a, sizeof(a)/sizeof(int), 0));
    
    return 0;
}
