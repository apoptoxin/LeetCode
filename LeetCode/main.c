//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "problem1.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {3,2,4};
    int *r = twoSum(&a, 3, 6);
    printf("%d %d",r[0], r[1]);
    return 0;
}
