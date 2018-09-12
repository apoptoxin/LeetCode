//
//  problem38.c
//  LeetCode
//
//  Created by apoptoxin on 2018/8/9.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem38.h"
#include <stdlib.h>

char* countAndSay(int n) {
    if (n <= 0) {
        return NULL;
    }
    if (n == 1) {
        char *r = malloc(sizeof(char)*2);
        r[0] = '1';
        r[1] = '\0';
        return r;
    }
    char *last = countAndSay(n-1);
    int length = strlen(last);
    int total = 0;
    char *re = NULL;
    char tmp = last[0];
    int curCount = 0;
    for (int i = 0 ; i < length ; i++) {
        if (tmp == last[i]) {
            //如果相等就计数加1并continue
            curCount++;
            continue;
        } else {
            //
            total += 2;
            if (re == NULL) {
                re = malloc(sizeof(char)*total);
            } else {
                re = realloc(re,sizeof(char)*total);
            }
            re[total-2] = '0' + curCount;
            re[total-1] = tmp;
            curCount = 1;
            tmp = last[i];
        }
    }
    total += 2;
    re = realloc(re,sizeof(char)*(total+1));
    re[total-2] = '0' + curCount;
    re[total-1] = tmp;
    re[total] = '\0';
    return re;
}

char* countAndSayF2(int n) {
    char *num = (char*)malloc(sizeof(char)*2);
    char *num1, *p, *q;
    int index;
    // char c;
    
    num[0] = '1';
    num[1] = '\0';
    while(n>1){
        index = 0;
        p = q = num;
        num1 = (char*)malloc(sizeof(char)*strlen(num)*2+1);
        
        while(*q){
            if(*p != (*(q + 1))){
                num1[index++] = q - p + '1';
                num1[index++] = *p;
                p = q + 1;
            }
            q++;
        }
        num1[index] = '\0';
        
        free(num);
        num = num1;
        
        n--;
    }
    
    return num;
}
