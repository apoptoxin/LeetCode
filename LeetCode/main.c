//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "problem15.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    char *s = "     -11009215950h";
    int a[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    int res = 0;
    printf("%s\n",threeSum(a, 15, &res));
    return 0;
}
