//
//  problem98.c
//  LeetCode
//
//  Created by 刘楠 on 2019/9/3.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem98.h"
#include <limits.h>

bool isValidBSTFromInOrder(struct TreeNode* root, long minValue, long maxValue) {
    if (root == NULL) {
        return true;
    }
    if (root->val < minValue || root->val > maxValue) {
        return false;
    }
    //左子树都应该在min和cur之间，右子数都应该在cur和max之间
    bool result = isValidBSTFromInOrder(root->left, minValue, root->val);
    result = result & isValidBSTFromInOrder(root->right, root->val, maxValue);
    return result;
}

bool isValidBST(struct TreeNode* root) {
    //中序遍历，每次读到的应该是递增的
    return isValidBSTFromInOrder(root, LONG_MIN, LONG_MAX);
}
