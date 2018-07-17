//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem18.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    char *s = "     -11009215950h";
    int a[] = {1, 0, -1, 0, -2, 2};
//    int length = sizeof(a) / sizeof(int);
    int returnSize = 0;
    int **re = fourSum(a, sizeof(a)/sizeof(int), 0, &returnSize);
    for (int i = 0 ; i < returnSize; i++) {
        int *p = re[i];
        printf("[%d, %d, %d, %d]",p[0],p[1],p[2],p[3]);
    }
//    printf("%d\n",threeSumClosest(a, length, 82));
    
    return 0;
}
