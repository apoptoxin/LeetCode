//
//  problem81.c
//  LeetCode
//
//  Created by liunan on 2019/6/19.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem81.h"

bool searchInRange(int* nums, int start, int end, int target);

bool search(int* nums, int numsSize, int target){
    int s = 0;
    int e = numsSize-1;
    return searchInRange(nums, s, e, target);
}

bool searchInRange(int* nums, int start, int end, int target) {
    // printf("在");
    // for (int i = start; i <= end; i++) {
    //     printf("%d ",nums[i]);
    // }
    // printf("中找%d\n",target);
    if (start > end) {
        return false;
    }
    if (end-start==1) {
        return nums[start] == target || nums[end] == target;
    }
    int middle = start + (end - start) * 0.5;
    if (nums[middle] == target) {
        return true;
    }
    if (nums[middle] < target) {
        bool find = false;
        if ((nums[start] > nums[middle]) || (nums[start] == nums[middle] && nums[middle] == nums[end])) {
            find = searchInRange(nums, start, middle-1, target);
        }
        if ((nums[middle] < nums[end]) || (nums[start] == nums[middle] && nums[middle] == nums[end]) || (nums[start] <= nums[middle] && nums[middle] > nums[end])) {
            find = find || searchInRange(nums, middle+1, end, target);
        }
        return find;
    } else {
        bool find = false;
        if ((nums[start] < nums[middle]) || (nums[start] == nums[middle] && nums[middle] == nums[end]) || (nums[start] > nums[middle] && nums[middle] <= nums[end])) {
            find = searchInRange(nums, start, middle-1, target);
        }
        if ((nums[middle] > nums[end]) || (nums[start] == nums[middle] && nums[middle] == nums[end])) {
            return find || searchInRange(nums, middle+1, end, target);
        }
        return find;
    }
}

//区分case就好，比较左中右，共9种case，对于这9中case区分旋转点在那边再判断是搜索左边还是右边还是都搜索或是都不搜索
