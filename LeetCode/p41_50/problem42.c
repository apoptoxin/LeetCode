//
//  problem42.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/16.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem42.h"

int trap(int* height, int heightSize) {
    int area = 0;
    int count = 0;
    int last = 0;
    for (int i = 0 ; i < heightSize ; i++) {
        if (height[i] <= height[last]) {
            count += height[i];
        } else {
            area += (height[last] * (i - last) - count);
            last = i;
            count = height[i];
        }
    }
    last = heightSize - 1;
    count = 0;
    for (int i = heightSize - 1 ; i >= 0 ; i--) {
        if (height[i] < height[last]) {
            count += height[i];
        } else {
            area += (height[last] * (last - i) - count);
            last = i;
            count = height[i];
        }
    }
    return area;
}
