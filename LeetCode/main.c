//
//  main.c
//  LeetCode
//
//  Created by apoptoxin on 2018/6/24.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "problem79.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    bool r = isNumber(" 005047e+6");//1
//    bool r = isNumber(".e");//1
    int returnSize = 0;
    char a[3][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    char **board = malloc (sizeof(char*) * 3);
    for (int i = 0; i < 3; i++) {
        board[i] = malloc(sizeof(char) * 4);
        for (int j = 0 ; j < 4 ; j++) {
            board[i][j] = a[i][j];
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    int *col = malloc(sizeof(int) * 3);
    for (int i = 0 ; i < 3; i++) {
        col[i] = 4;
    }
    char *word = "ABCCED";
    printf("%d\n", exist(board, 3, col, word));
    return 0;
}
