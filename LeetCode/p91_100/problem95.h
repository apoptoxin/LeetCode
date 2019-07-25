//
//  problem95.h
//  LeetCode
//
//  Created by liunan on 2019/7/24.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#ifndef problem95_h
#define problem95_h

#include <stdio.h>
#include "node.h"

#endif /* problem95_h */

//给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
//
//示例:
//
//输入: 3
//输出:
//[
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
//]

struct TreeNode** generateTrees(int n, int* returnSize);
