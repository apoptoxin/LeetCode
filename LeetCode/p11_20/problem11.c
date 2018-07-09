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
    int max = 0;
    for (int i=0,j = heightSize-1; i<j;) {
        int high = height[i];
        if (height[i] >= height[j]) {
            high = height[j];
        }
        int area = high * (j-i);
        if (area > max) {
            max = area;
        }
        if (height[i] <= height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return max;
//    int max = 0;
//    for (int i=0,j = heightSize-1; i<j;) {
//        int high = height[i] > height[j] ? height[i] : height[j];
//        int area = high * (j-i);
//        max = max > area ? max : area;
//        if (height[i] < height[j]) {
//            i++;
//        } else {
//            j--;
//        }
//    }
//    return max;
}

int maxArea(int* height, int heightSize) {
    return maxAreaWithTwoPtr(height, heightSize);
}

