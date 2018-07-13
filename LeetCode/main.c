//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem15.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    char *s = "     -11009215950h";
    int a[] = {-1,2,1,-4};
    int res = 0;
//    printf("%s\n",threeSum(a, 15, &res));
    
    quickSort(a, sizeof(a) / sizeof(a[0]));
    for (int i = 0 ; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%d ",a[i]);
    }
    return 0;
}
