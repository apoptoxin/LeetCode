//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem40.h"

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
    int a[] = {2,5,2,1,2};
//    int *p = malloc(sizeof(a)/sizeof(int));
//    int size = 0;
//    for (int i = 0 ; i < sizeof(a)/sizeof(int) ; i++) {
//        p[i] = a[i];
//        size++;
//    }
    int returnSize = 0;
    int *colSize = malloc(sizeof(int) * 1000);
    int ** colS = combinationSum2(a, sizeof(a)/sizeof(int), 5, &colSize, &returnSize);
//    int re = 0;
//    int total = 0;
//    int **r = permute(a, sizeof(a)/sizeof(int), &total);
//    printf("%d\n",jump(a, sizeof(a)/sizeof(int)));
    return 0;
}
