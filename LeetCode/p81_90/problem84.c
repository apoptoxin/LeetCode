//
//  problem84.c
//  LeetCode
//
//  Created by liunan on 2019/6/25.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem84.h"

int largestRectangleArea(int* heights, int heightsSize){
    if (heightsSize <= 0) {
        return 0;
    }
    int cur = -1;
    int max = 0;
    int *stack = malloc(sizeof(int) * heightsSize);
    for (int i = 0 ; i < heightsSize; i++) {
        if (cur == -1 || heights[i] >= heights[stack[cur]]) {
            //栈空或者当前大于栈顶，入栈
            stack[++cur] = i;
        } else {
            while (cur >= 0 && heights[i] < heights[stack[cur]]) {
                int nowHeight = heights[stack[cur]];
                int nowSize = 0;
                cur--;
                if (cur < 0) {
                    nowSize = nowHeight * i;
                } else {
                    int nowIndex = stack[cur]+1;
                    nowSize = nowHeight * (i-nowIndex);
                }
                max = max > nowSize ? max : nowSize;
            }
            stack[++cur] = i;
        }
    }
    
    //结束后如果栈还有元素的话挨个出栈
    while (cur >= 0) {
        int nowHeight = heights[stack[cur]];
        int nowSize = 0;
        cur--;
        if (cur < 0) {
            nowSize = nowHeight * heightsSize;
        } else {
            int nowIndex = stack[cur]+1;
            nowSize = nowHeight * (heightsSize-nowIndex);
        }
        max = max > nowSize ? max : nowSize;
    }
    return max;
}

//用栈来做
//if 当前元素大于等于栈顶元素 then 入栈
//else 出栈并更新max
//
//更新方法，出栈后，如果当前栈不为空，则用出栈这个元素的高度乘以（当前下标-当前栈顶元素的下标-1）
//如果出栈后栈顶为空，说明之前所有元素都大于出栈这个元素（如果小于的话就不会出栈了就不会导致空栈），就用出栈这个元素的高度乘以当前下标
//每个元素都经历了一次入栈和一次出栈，所以时间复杂度为O(n)
