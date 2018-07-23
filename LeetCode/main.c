//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem22.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int size = 0;
    char **s = generateParenthesis(3, &size);
    for (int i = 0 ; i < size; i++) {
        printf("%s\n", s[i]);
    }
//    printf("%d\n",isValid(s));
    
    return 0;
}
