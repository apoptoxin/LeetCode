//
//  main.c
//  LeetCode
//
//  Created by apoptoxin on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem87.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char *s1 = "abc";
    char *s2 = "bca";
    printf("%s\n", isScramble(s1, s2) ? "YES" : "NO");
    return 0;
}
