//
//  main.c
//  LeetCode
//
//  Created by apoptoxin on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem81.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    bool r = isNumber(" 005047e+6");//1
//    bool r = isNumber(".e");//1
    int a[100] = {10,10,10,-10,-10,-10,-10,-9,-9,-9,-9,-9,-9,-9,-8,-8,-8,-8,-8,-8,-8,-8,-7,-7,-7,-7,-6,-6,-6,-5,-5,-5,-4,-4,-4,-4,-3,-3,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,2,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,7,7,7,7,7,8,8,8,8,9,9,9,9,9,9,9,10,10};
    int size = 100;
    int *ori = malloc(sizeof(int) * size);
    for (int i = 0 ; i < size; i++) {
        ori[i] = a[i];
    }
    printf("%s\n", search(ori, size, -6) ? "YES" : "NO");
    return 0;
}
