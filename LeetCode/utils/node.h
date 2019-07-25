//
//  node.h
//  LeetCode
//
//  Created by liunan on 2019/6/24.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef node_h
#define node_h

#include <stdio.h>

#endif /* node_h */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
