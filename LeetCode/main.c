//
//  main.c
//  LeetCode
//
//  Created by apoptoxin on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem78.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    bool r = isNumber(" 005047e+6");//1
//    bool r = isNumber(".e");//1
    int returnSize = 0;
    int *col = malloc(sizeof(int));
    int a[3] = {1,2,3};
    int **re = subsets(a, 3, &returnSize, &col);
//    printf("%s\n", minWindow(s,t));
    return 0;
}

//=================================================================
//==30==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000019 at pc 0x000000401c4b bp 0x7ffdd887d6b0 sp 0x7ffdd887d6a8
//READ of size 1 at 0x602000000019 thread T0
//#2 0x7febe9cf92e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)
//
//0x602000000019 is located 0 bytes to the right of 9-byte region [0x602000000010,0x602000000019)
//                                                                 allocated by thread T0 here:
//#0 0x7febeb1832b0 in malloc (/usr/local/lib64/libasan.so.5+0xe82b0)
//#4 0x7febe9cf92e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)
//                                                                 
//                                                                 Shadow bytes around the buggy address:
//                                                                 0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//                                                                 0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//                                                                 0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//                                                                 0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//                                                                 0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//                                                                 =>0x0c047fff8000: fa fa 00[01]fa fa 00 01 fa fa fa fa fa fa fa fa
//                                                                 0x0c047fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//                                                                 0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//                                                                 0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//                                                                 0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//                                                                 0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//                                                                 Shadow byte legend (one shadow byte represents 8 application bytes):
//                                                                 Addressable:           00
//                                                                 Partially addressable: 01 02 03 04 05 06 07
//                                                                 Heap left redzone:       fa
//                                                                 Freed heap region:       fd
//                                                                 Stack left redzone:      f1
//                                                                 Stack mid redzone:       f2
//                                                                 Stack right redzone:     f3
//                                                                 Stack after return:      f5
//                                                                 Stack use after scope:   f8
//                                                                 Global redzone:          f9
//                                                                 Global init order:       f6
//                                                                 Poisoned by user:        f7
//                                                                 Container overflow:      fc
//                                                                 Array cookie:            ac
//                                                                 Intra object redzone:    bb
//                                                                 ASan internal:           fe
//                                                                 Left alloca redzone:     ca
//                                                                 Right alloca redzone:    cb
//                                                                 ==30==ABORTING
