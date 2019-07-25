//
//  problem95.c
//  LeetCode
//
//  Created by liunan on 2019/7/24.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem95.h"

struct TreeNode** generateTreesFromStartToEnd(int start, int end, int* returnSize);

struct TreeNode** generateTrees(int n, int* returnSize){
    if (n <= 0) {
        if (returnSize) {
            *returnSize = 0;
        }
        return NULL;
    }
    return generateTreesFromStartToEnd(1, n, returnSize);
}

struct TreeNode** generateTreesFromStartToEnd(int start, int end, int* returnSize) {
    if (end < start) {
        return NULL;
    }
    if (start == end) {
        struct TreeNode** result = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        struct TreeNode* value = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        value->val = start;
        value->left = NULL;
        value->right = NULL;
        result[0] = value;
        if (returnSize) {
            *returnSize = 1;
        }
        return result;
    }
    int curCount = 0;
    struct TreeNode** result = NULL;
    for (int i = start ; i <= end ; i++) {
        int leftCount = 0;
        struct TreeNode** left = generateTreesFromStartToEnd(start, i-1, &leftCount);
        int rightCount = 0;
        struct TreeNode** right = generateTreesFromStartToEnd(i+1, end, &rightCount);
        printf("%d to %d, cur:%d, leftCount:%d, rightCount:%d\n",start, end, i, leftCount, rightCount);
        if (leftCount == 0 && rightCount == 0) {
            if (curCount == 0) {
                result = malloc(sizeof(struct TreeNode*));
            } else {
                result = realloc(result, sizeof(struct TreeNode*) * (curCount+1));
            }
            struct TreeNode* value = malloc(sizeof(struct TreeNode));
            value->val = i;
            value->left = NULL;
            value->right = NULL;
            result[curCount++] = value;
            return result;
        } else if (leftCount == 0) {
            if (curCount == 0) {
                result = malloc(sizeof(struct TreeNode*) * rightCount);
            } else {
                result = realloc(result, sizeof(struct TreeNode*) * (curCount+rightCount));
            }
            for (int j = 0; j < rightCount; j++) {
                struct TreeNode* value = malloc(sizeof(struct TreeNode));
                value->val = i;
                value->left = NULL;
                value->right = right[j];
                result[curCount++] = value;
            }
        } else if (rightCount == 0) {
            if (curCount == 0) {
                result = malloc(sizeof(struct TreeNode*) * leftCount);
            } else {
                result = realloc(result, sizeof(struct TreeNode*) * (curCount+leftCount));
            }
            for (int j = 0; j < leftCount; j++) {
                struct TreeNode* value = malloc(sizeof(struct TreeNode));
                value->val = i;
                value->left = left[j];
                value->right = NULL;
                result[curCount++] = value;
            }
        } else {
            if (curCount == 0) {
                result = malloc(sizeof(struct TreeNode*) * (leftCount * rightCount));
            } else {
                result = realloc(result, sizeof(struct TreeNode*) * (curCount+leftCount*rightCount));
            }
            for (int m = 0; m < leftCount; m++) {
                for (int n = 0; n < rightCount; n++) {
                    struct TreeNode* value = malloc(sizeof(struct TreeNode));
                    value->val = i;
                    value->left = left[m];
                    value->right = right[n];
                    result[curCount++] = value;
                }
            }
        }
    }
    if (returnSize) {
        *returnSize = curCount;
    }
    return result;
}
