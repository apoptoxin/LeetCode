//
//  problem15.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/11.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem15.h"
#include <stdlib.h>

struct ResultNode {
    int* result;
    struct ResultNode *next;
};

typedef struct ResultNode ResultNode;

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    ResultNode *head = NULL;
    ResultNode *cur = head;
    int total = 0;
    for (int i = 0 ; i < numsSize - 1; i++) {
        while (i>0 && nums[i]==nums[i-1]) {
            i++;
        }
        //固定最小元素位置，在后面找两个元素和为-nums[i]的
        for (int j = i+1, end = numsSize-1 ; j < end ;) {
            printf("%d %d %d \n",i,j,end);
            //以i, j, end 这3个元素判断是否满足条件；
            int cal = nums[i] + nums[j] + nums[end];
            if (cal == 0) {
                ResultNode *node = malloc(sizeof(ResultNode));
                int* result = malloc(sizeof(int) * 3);
                result[0] = nums[i];
                result[1] = nums[j];
                result[2] = nums[end];
                node->result = result;
                node->next = NULL;
                if (head == NULL) {
                    head = node;
                    cur = head;
                } else {
                    cur->next = node;
                    cur = node;
                }
                total++;
                ++j;
                while (end > j && nums[j] == nums[j-1]) j++;
            } else if (cal > 0) {
                --end;
                while (end > j && nums[end+1] == nums[end]) end--;
            } else {
                ++j;
                while (end > j && nums[j] == nums[j-1]) j++;
            }
        }
    }
    *returnSize = total;
    int **result = malloc(sizeof(int *) * total);
    for (int i = 0 ; i < total ; i++) {
        result[i] = head->result;
        head = head->next;
    }
    ResultNode *ptr = head;
    while (ptr != NULL) {
        ptr = head->next;
        free(head);
        head = ptr;
    }
    free(head);
    return result;
}
