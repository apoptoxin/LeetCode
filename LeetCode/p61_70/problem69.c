//
//  problem69.c
//  LeetCode
//
//  Created by 刘楠 on 2018/11/8.
//  Copyright © 2018 micronil.com. All rights reserved.
//

#include "problem69.h"

int mySqrt(int x) {
    int left = 0;
    int right = x;
    int middle = left + (right - left) / 2;
    
    while (middle != 0 && x / middle != middle) {
        if (x / middle < middle) {
            right = middle - 1;
        } else {
            if (x / (middle+1) < (middle+1)) {
                return middle;
            } else {
                left = middle + 1;
            }
        }
        middle = left + (right - left) / 2;
    }
    return middle == 0 ? x : middle;
}
