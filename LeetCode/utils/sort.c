//
//  sort.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "sort.h"
#include "swap.h"

void quickSortWithStartAndEnd(int* ori, int start, int end) {
    if (start >= end) return;
    int from = start + 1;
    int to = end;
    while (from < to) {
        //为什么先从尾部往前判断：原因就是避免判断是否所有元素都小于等于哨兵
        while(from <= to && ori[to] > ori[start]) --to;
        while (from < to && ori[from] < ori[start]) ++from;
        if (to > from) swapTwoInts(&ori[from], &ori[to]);
    }
    swapTwoInts(&ori[start], &ori[to]);
    quickSortWithStartAndEnd(ori, start, to-1);
    quickSortWithStartAndEnd(ori, to+1, end);
}

void quickSort(int * oriAry, int length) {
    quickSortWithStartAndEnd(oriAry, 0, length-1);
}


