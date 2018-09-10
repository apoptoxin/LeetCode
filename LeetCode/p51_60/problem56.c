//
//  problem56.c
//  LeetCode
//
//  Created by 刘楠 on 2018/9/10.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem56.h"
#include <stdlib.h>

int cmpfunc56 (const void * a, const void * b)
{
    struct Interval* ori1 = (struct Interval *)a;
    struct Interval* ori2 = (struct Interval *)b;
    return (*ori1).start - (*ori2).start;
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    qsort(intervals,intervalsSize,sizeof(struct Interval),cmpfunc56);
    int size = 0;
    struct Interval *re = NULL;
    int start = 0;
    int end = 0;
    int find = 0;
    for (int i = 0 ; i < intervalsSize; i++) {
        if (find == 0) {
            start = (intervals[i]).start;
            end = (intervals[i]).end;
            find = 1;
        } else {
            if (intervals[i].start <= end) {
                end = intervals[i].end > end ? intervals[i].end : end;
                find = 1;
            } else {
                find = 0;
                if (size == 0) {
                    re = malloc(sizeof(struct Interval));
                    struct Interval t = {.start=start,.end=end};
                    re[0] = t;
                    size++;
                } else {
                    re = realloc(re, (size+1)*sizeof(struct Interval));
                    struct Interval t = {.start=start,.end=end};
                    re[size] = t;
                    size++;
                }
                start = intervals[i].start;
                end = intervals[i].end;
                find = 1;
            }
        }
    }
    if (find == 1) {
        if (size == 0) {
            re = malloc(sizeof(struct Interval));
            struct Interval t = {.start=start,.end=end};
            re[0] = t;
            size++;
        } else {
            re = realloc(re, (size+1)*sizeof(struct Interval));
            struct Interval t = {.start=start,.end=end};
            re[size] = t;
            size++;
        }
    }
    if (returnSize) {
        *returnSize = size;
    }
    return re;
    
}
