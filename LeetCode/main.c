//
//  main.c
//  LeetCode
//
//  Created by apoptoxin on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem68.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    bool r = isNumber(" 005047e+6");//1
//    bool r = isNumber(".e");//1
    int size = 0;
    char* words[6] = {"What","must","be","acknowledgment","shall","be"};
    char** re = fullJustify(words, 6, 16, &size);
    return 0;
}
