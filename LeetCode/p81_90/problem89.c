//
//  problem89.c
//  LeetCode
//
//  Created by liunan on 2019/7/2.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem89.h"
#include <math.h>

int* grayCode(int n, int* returnSize){
    int size = pow(2, n);
    *returnSize = size;
    int* re = malloc(sizeof(int) * size);
    for (int cur = 0; cur < size ; cur++) {
        re[cur] = (cur >> 1) ^ cur;
    }
    return re;
}

//https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81#%E4%BA%8C%E9%80%B2%E4%BD%8D%E6%95%B8%E8%BD%89%E6%A0%BC%E9%9B%B7%E7%A2%BC
//G(n) = B(n+1) XOR B(n) 
