//
//  problem32.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/5.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem32.h"
#include "bool_define.h"

int longestValidParentheses(char* s) {
    int length = strlen(s);
    int total = 0;
    int *a = malloc(sizeof(int) * length);
    //用a来记录从第i个元素开始最长的有效括号长度
    //a[i]就等于：
    //1.如果s[i]为')'，则a[i]=0
    //int tmp = 0
    //2.计算a[i+2]开始最长+s[i]和s[i+1]，得到长度l1，然后累加上a[i+l1]得到l1;
    //3.计算a[i+1]开始最长，为l2,加上s[i]和s[i+l2],结果存在l2,然后累加上a[i+l2]得到l2;
    //a[i]=l1和l2最大的
    
    //从length-2开始，因为最后一位一定是0
    for (int i = length-1; i >= 0; i--) {
        //如果是')'就没必要计算了，结果就是0
        if (i < length -1 && s[i] == '(') {
            //step1,计算i+2开始的值
            int l1 = 0;
            if (s[i+1] == ')') {
                l1 = 2;
                if (i+l1 < length) {
                    l1 = a[i+l1] + l1;
                }
            }
            //step2,计算i+1
            int l2 = 0;
            if (i+1+a[i+1] < length && s[i+1+a[i+1]] == ')') {
                l2 = a[i+1] + 2;
                if (i+l2 < length) {
                    l2 = a[i+l2]+l2;
                }
            }
            //比较l1和l2，取大的
            a[i] = l1>l2?l1:l2;
            total = total > a[i] ?total:a[i];
        } else {
            a[i] = 0;
        }
    }
    
    return total;
}
