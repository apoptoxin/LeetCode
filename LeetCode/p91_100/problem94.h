//
//  problem94.h
//  LeetCode
//
//  Created by liunan on 2019/7/18.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef problem94_h
#define problem94_h

#include <stdio.h>
#include "node.h"
#endif /* problem94_h */

//给定一个二叉树，返回它的中序 遍历。
//
//示例:
//
//输入: [1,null,2,3]
//1
//\
//2
///
//3
//
//输出: [1,3,2]
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？

int* inorderTraversal(struct TreeNode* root, int* returnSize);
