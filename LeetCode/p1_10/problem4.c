//
//  problem4.c
//  LeetCode
//
//  Created by apoptoxin on 2018/6/25.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem4.h"

double findKthSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    if (nums1Size + nums2Size < k || (nums1Size+nums2Size==0)) {
        //数据错误，k大于两个数组的长度和
        return 0.0f;
    }
    
    
    int lowMid = (nums1Size + 1)/2;
    int highMid = (nums2Size + 1)/2;
    
    
    //这里写结束条件
    if (nums1Size == 0) {
        return nums2[k-1];
    } else if (nums2Size == 0) {
        return nums1[k-1];
    } else if (nums1Size == 1 && nums2Size == 1) {
        if (nums1[0] < nums2[0]) {
            return k == 1 ? nums1[0] : nums2[0];
        } else {
            return k == 2 ? nums1[0] : nums2[0];
        }
    } else if (nums1Size == 1) {
        int mid = nums2Size / 2;
        if (nums2[mid] <= nums1[0]) {
            if (mid >= k-1) {
                return nums2[k-1];
            } else {
                return findKthSortedArrays(nums1, nums1Size, nums2+mid+1, nums2Size - mid - 1, k-mid-1);
            }
        } else {
            if (mid>k-2) {
                return findKthSortedArrays(nums1, nums1Size, nums2, mid, k);
            } else {
                return nums2[k-2];
            }
        }
    } else if (nums2Size == 1) {
        return findKthSortedArrays(nums2, nums2Size, nums1, nums1Size, k);
    } else if (nums1[lowMid] > nums2[highMid]) {
        return findKthSortedArrays(nums2, nums2Size, nums1, nums1Size, k);
    } else {
        if (lowMid + 1 >= k) {
            return findKthSortedArrays(nums1, lowMid+1, nums2, highMid, k);
        } else {
            if (lowMid + 1 + highMid + 1 <=k) {
                return findKthSortedArrays(nums1+lowMid+1, nums1Size-lowMid-1, nums2, nums2Size, k-lowMid-1);
            } else {
                return findKthSortedArrays(nums1, nums1Size, nums2, highMid, k);
            }
        }
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size + nums2Size == 0) {
        return 0.0f;
    }
    if ((nums1Size + nums2Size)%2==0) {
        double target1 = (double)findKthSortedArrays(nums1, nums1Size, nums2, nums2Size, (nums1Size+nums2Size)/2);
        double target2 = (double)findKthSortedArrays(nums1, nums1Size, nums2, nums2Size, (nums1Size+nums2Size)/2+1);
        return (target1 + target2) /2.0f;
    } else {
        return (double)findKthSortedArrays(nums1, nums1Size, nums2, nums2Size, (nums1Size+nums2Size)/2+1);
    }
}
