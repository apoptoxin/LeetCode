//
//  problem28.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/30.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem28.h"
#include "kmp.h"

int strStr(char* haystack, char* needle) {
    return kmpSearch(haystack, needle);
}
