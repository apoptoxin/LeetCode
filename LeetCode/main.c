//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "problem14.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    char *s = "     -11009215950h";
    char** a = malloc(sizeof(char*) * 3);//{"flower","flow","flight"};
    a[0] = "flower";
    a[1] = "flow";
    a[2] = "flight";
    printf("%d\n",longestCommonPrefix(a, 3));
    return 0;
}
