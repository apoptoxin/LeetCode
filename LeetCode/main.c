//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem57.h"

int main(int argc, const char * argv[]) {
    // insert code here...

    //[[1,3],[2,6],[8,10],[15,18]]
    struct Interval *list = malloc(2*sizeof(struct Interval));
    list[0] = (struct Interval){.start=1,.end=5};
    list[1] = (struct Interval){.start=6,.end=9};
//    list[2] = (struct Interval){.start=8,.end=10};
//    list[3] = (struct Interval){.start=15,.end=18};
    int size = 0;
    insert(list, 4, (struct Interval){.start=5,.end=7},&size);
    return 0;
}
