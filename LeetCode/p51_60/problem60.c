//
//  problem60.c
//  LeetCode
//
//  Created by 刘楠 on 2018/9/11.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem60.h"

char* getPermutation(int n, int k) {
    //n->[1,9],9个数
    int pos[9] = {1,2,3,4,5,6,7,8,9};
    int tmp = 1;
    for (int i = 1 ; i < n; i++) {
        tmp *= i;
    }
    char *re = malloc(sizeof(char) * (n+1));
    re[n] = '\0';
    for (int i = 0,last = k-1 ; i < n; i++) {
        //循环n次，每次找到最高位
//        if (i != n-1) {
            int p = last / tmp;
            last = last - p * tmp;
        
            if (i >= n-2) {
                tmp = 2;
            } else {
                tmp = tmp / (n-i-1);
            }
            int find = 0;
            int index = -1;
            while (find <= p) {
                index++;
                if (pos[index] != 0) {
                    find++;
                }
            }
            re[i] = '0'+pos[index];
            pos[index] = 0;
        
        
    }
    return re;
}
