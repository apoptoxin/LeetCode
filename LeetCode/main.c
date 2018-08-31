//
//  main.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem49.h"

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
    char ori[6][3] = {{'e','a','t'}, {'t','e','a'}, {'t','a','n'},{'a','t','e'},{'n','a','t'},{'b','a','t'}};
    char **s = malloc(sizeof(char *)*9);
    for (int i = 0; i < 6; i++) {
        char *t = malloc(sizeof(char)*3);
        for (int j = 0; j<3; j++) {
            t[j] = ori[i][j];
        }
        s[i] = t;
    }
    int c = 0;
    int b = 0;
    int *p = &c;
    groupAnagrams(s,6,&p,&b);
//    solveSudoku(s, 9, 9);
    for (int i = 0 ; i < b; i++) {
        for (int j = 0; j < p[i]; j++) {
            printf("%s ",s[i][j]);
        }
        printf("\n");
    }
//    int a[] = {-1,2,0,-1,1,0,1};
//    int *p = malloc(sizeof(a)/sizeof(int));
//    int size = 0;
//    for (int i = 0 ; i < sizeof(a)/sizeof(int) ; i++) {
//        p[i] = a[i];
//        size++;
//    }
//    int returnSize = 0;
//    int numsSize = sizeof(a) / sizeof(int);
//    int ** colS = permuteUnique(a, numsSize, &returnSize);
//    int re = 0;
//    int total = 0;
//    int **r = permute(a, sizeof(a)/sizeof(int), &total);
//    printf("%d\n",jump(a, sizeof(a)/sizeof(int)));
//    for (int i = 0 ; i < returnSize ; i++) {
//        for (int j = 0 ; j < numsSize; j++) {
//            printf("%d ",colS[i][j]);
//        }
//        printf("\n");
//    }
    
//    printf("\ncount:%f\n",myPow(34.00515, -3));
//    printf("\nre:%f\n",pow(34.00515,-3));
    return 0;
}
