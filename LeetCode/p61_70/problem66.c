//
//  problem66.c
//  LeetCode
//
//  Created by liunan on 2018/11/6.
//  Copyright © 2018 micronil.com. All rights reserved.
//

#include "problem66.h"

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int addition = 1;
    int totalLength = digitsSize+1;
    int* result = malloc(sizeof(int)*totalLength);
    for (int i = digitsSize - 1 ; i >= 0 ; i--) {
        int cur = digits[i] + addition;
        result[i+1] = cur % 10;
        addition = cur / 10;
    }
    if (addition != 0) {
        *returnSize = totalLength;
        result[0] = addition;
        return result;
    } else {
        *returnSize = totalLength-1;
        return &(result[1]);
    }
}
