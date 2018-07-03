//
//  problem6.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/1.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem6.h"
//2kn-2k+-p p表示列，k表示行

char* convert(char* s, int numRows) {
    int n = numRows;
    int length = strlen(s);
    if (numRows == 1 || length < 1 || length <= numRows) {
        return s;
    }
    char *result = malloc(sizeof(char) * (length + 1));
    result[length] = '\0';
    int i = 0;
    int column = (length+(2*n-3)/(2*(n-1)));
//    n-1不会等于1了
    for (int p = 0; p < n ; p++) {
        for (int k = 0 ; k < column ; k++) {
            if (p == 0 || p == n-1) {
                if (2*k*n - 2*k - p >= 0 && 2*k*n - 2*k - p < length) {
                    result[i] = s[2*k*n - 2*k - p];
                    ++i;
//                    printf("%d个元素是原下标%d\n",i-1,2*k*n - 2*k - p);
                }
            } else {
                if (2*k*n - 2*k - p >= 0  && 2*k*n - 2*k - p < length) {
                    result[i] = s[2*k*n - 2*k - p];
                    ++i;
//                    printf("%d个元素是原下标%d\n",i-1,2*k*n - 2*k - p);
                }
                if (2*k*n - 2*k + p < length && 2*k*n - 2*k + p >= 0) {
                    result[i] = s[2*k*n - 2*k + p];
                    ++i;
//                    printf("%d个元素是原下标%d\n",i-1,2*k*n - 2*k + p);
                }
            }

        }
    }
    return result;
}
