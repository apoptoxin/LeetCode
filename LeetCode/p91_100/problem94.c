//
//  problem94.c
//  LeetCode
//
//  Created by liunan on 2019/7/18.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem94.h"

struct HeapNode {
    int val;
    struct HeapNode *next;
    struct TreeNode *value;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        if (returnSize) {
            *returnSize = 0;
        }
        return NULL;
    }
    int *result = NULL;
    int totalSize = 0;
    struct HeapNode *head = malloc(sizeof(struct HeapNode));
    head->val = 0;
    head->next = NULL;
    head->value = root;
    while (head != NULL) {
        printf("read ");
        struct HeapNode *cur = head;
        head = head->next;
        if (cur->val > 0) {
            if (totalSize == 0) {
                result = malloc(sizeof(int));
                result[0] = cur->value->val;
                totalSize = 1;
            } else {
                printf("prerealloc:%d ",totalSize+1);
                result = realloc(result, sizeof(int) * (totalSize+1));
                result[totalSize] = cur->value->val;
                totalSize++;
                printf("afterrealloc: ");
            }
//            free(cur);
        } else {
            if (cur->value->right != NULL) {
                struct HeapNode *curTmp = (struct HeapNode*)malloc(sizeof(struct HeapNode));
                curTmp->val = 0;
                curTmp->next = head;
                curTmp->value = cur->value->right;
                head = curTmp;
                printf("l ");
            }
            cur->val = cur->val+1;
            cur->next = head;
            head = cur;
            printf("c ");
            if (cur->value->left != NULL) {
                struct HeapNode *curTmp = (struct HeapNode*)malloc(sizeof(struct HeapNode));
                curTmp->val = 0;
                curTmp->next = head;
                curTmp->value = cur->value->left;
                head = curTmp;
                printf("r ");
            }
        }
    }
    if (returnSize) {
        *returnSize = totalSize;
    }
    return result;
}
