//
//  problem11.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/7.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem11.h"

int maxInt(int a, int b) {
    return a>b ? a:b;
}

int minInt(int a, int b) {
    return a<b ? a:b;
}

int maxAreaWithOn2(int* height, int heightSize) {
    int max = 0;
    for (int i = 0 ; i < heightSize ; i++) {
        for (int j  = i+1; j<heightSize; j++) {
            max = maxInt(max,minInt(height[i], height[j])*(j-i));
        }
    }
    return max;
}

// 面积=长*宽，同样宽度下，长度越长面积越大，所以初始阶段应该就是第一个点和最后一个点围成的面积最大，然后逐渐向中间收拢找到高度比外围高度高度高的，比较面积


int maxAreaWithTwoPtr(int *height, int heightSize) {
    int max = (height[0] < height[heightSize-1] ? height[heightSize - 1]:height[0]) * (heightSize);
    int left = 0;
    int right = heightSize - 1;
    for (int i=0,j = heightSize-1; i<j;) {
        //因为如果height[j] < height[right],那么从left到j组成的面积肯定比left到right小，所以没必要计算
        while (height[j] <= height[right]) j--;
        //计算一次
        int area = maxInt(height[left], height[j]) * (j-left);
        if (area > max) {
            max = area;
            right = j;
        }
        while (height[i] <= height[left]) i++;
        area = maxInt(height[i], height[j]);
        if (area > max) {
            max = area;
            left = i;
        }
    }
    return max;
}

int maxArea(int* height, int heightSize) {
    return maxAreaWithOn2(height, heightSize);
}

