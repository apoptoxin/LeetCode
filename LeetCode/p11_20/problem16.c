//
//  problem16.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/13.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem16.h"
#include "sort.h"

int threeSumClosest(int* nums, int numsSize, int target) {
    quickSort(nums, numsSize);
    if (numsSize < 3) {
        return 0;
    }
    int total = nums[0] + nums[1] + nums[2];
    for (int i = 0 ; i < numsSize - 1; i++) {
        //固定最小元素位置，在后面找两个元素和为-nums[i]的
        for (int j = i+1, end = numsSize-1 ; j < end ;) {
            //以i, j, end 这3个元素判断是否满足条件；
            int cal = nums[i] + nums[j] + nums[end];
//            printf("%d %d %d cal:%d cur:%d ",nums[i],nums[j],nums[end],cal,total);
            int minus = abs(cal - target);
            int oriMinus = abs(total - target);
            total = minus < oriMinus ? cal : total;
//            printf("更新后cur:%d\n",total);
            if (cal > target) {
                --end;
            } else {
                ++j;
            }
        }
    }
    return total;
}
