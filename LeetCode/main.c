//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "problem4.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int num1[] = {3,3,3,3};
    int num2[] = {3,3,3,3};
    printf("%f\n",findMedianSortedArrays(num1, sizeof(num1)/sizeof(int), num2, sizeof(num2)/sizeof(int)));
    return 0;
}
