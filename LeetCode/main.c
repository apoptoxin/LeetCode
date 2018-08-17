//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem43.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    char a[9][9] = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
//    char **s = malloc(sizeof(char *)*9);
//    for (int i = 0; i < 9; i++) {
//        char *t = malloc(sizeof(char)*9);
//        for (int j = 0; j<9; j++) {
//            t[j] = a[i][j];
//        }
//        s[i] = t;
//    }
//    solveSudoku(s, 9, 9);
//    for (int i = 0 ; i < 9; i++) {
//        for (int j = 0; j < 9; j++) {
//            printf("%c ",s[i][j]);
//        }
//        printf("\n");
//    }
    int a[] = {1,2,3,2,5};
//    int *p = malloc(sizeof(a)/sizeof(int));
//    int size = 0;
//    for (int i = 0 ; i < sizeof(a)/sizeof(int) ; i++) {
//        p[i] = a[i];
//        size++;
//    }
//    int ** colS = malloc(sizeof(int*)*10000);
//    int re = 0;
//    int **r = combinationSum2(p, size, 8, colS, &re);
    printf("%s\n",multiply("140", "721"));
    return 0;
}
