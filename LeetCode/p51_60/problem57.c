//
//  problem57.c
//  LeetCode
//
//  Created by 刘楠 on 2018/9/10.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem57.h"

struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    
    int size = 0;
    struct Interval *re = NULL;
    if (intervalsSize == 0) {
        re = malloc(sizeof(struct Interval));
        re[0] = (struct Interval){.start=newInterval.start,.end=newInterval.end};
        if (returnSize) {
            *returnSize = 1;
        }
        return re;
    }
    int start = 0;
    int end = 0;
    int find = 0;
    int didReadNew = 0;
    for (int i = 0 ; i < intervalsSize; i++) {
        int needReread = !didReadNew && newInterval.start <= ((struct Interval)(intervals[i])).start;
        struct Interval cur = intervals[i];
        if (needReread) {
            cur = newInterval;
            didReadNew = 1;
            i--;
        }
        
        if (find == 0) {
            start = cur.start;
            end = cur.end;
            find = 1;
        } else {
            if (cur.start <= end) {
                end = cur.end > end ? cur.end : end;
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
                start = cur.start;
                end = cur.end;
                find = 1;
            }
        }
    }
    while (find == 1 || didReadNew == 0) {
        if (didReadNew == 0) {
            if (newInterval.start <= end) {
                end = newInterval.end > end ? newInterval.end : end;
            } else {
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
                start = newInterval.start;
                end = newInterval.end;
            }
            didReadNew = 1;
            continue;
        }
        
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
    }
    if (returnSize) {
        *returnSize = size;
    }
    return re;
}
