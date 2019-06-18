//
//  problem79.c
//  LeetCode
//
//  Created by liunan on 2019/6/13.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem79.h"

bool existWithSteps(char** board, int boardSize, int* boardColSize, char * word, int curIndex, int** steps, int curx, int cury);

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    if (boardSize <= 0) {
        return false;
    }
    int** tmp = malloc(sizeof(int*) * boardSize);
    for (int i = 0 ; i < boardSize ; i++) {
        tmp[i] = calloc(boardColSize[i], sizeof(int));
    }
    bool find = false;
    for (int x = 0 ; x < boardSize ; x++) {
        for (int y = 0 ; y < boardColSize[x]; y++) {
            find = existWithSteps(board, boardSize, boardColSize, word, 0, tmp, x, y);
            if (find) {
                break;
            }
        }
        if (find) {
            break;
        }
    }
    return find;
}

bool existWithSteps(char** board, int boardSize, int* boardColSize, char * word, int curIndex, int** steps, int curx, int cury) {
    //curx,cury位置的是否与word[curindex]匹配
    if (board[curx][cury] != word[curIndex]) {
        return false;
    }
    if (curIndex >= strlen(word)-1) {
        return true;
    }
    steps[curx][cury] = 1;
    bool find = false;
    if (curx > 0 && boardColSize[curx-1] > cury && steps[curx-1][cury] == 0 ) {
        //上
        find = find || existWithSteps(board, boardSize, boardColSize, word, curIndex+1, steps, curx-1, cury);
    }
    if (curx < boardSize-1 && boardColSize[curx+1] > cury && steps[curx+1][cury] == 0 ) {
        //下
        find = find || existWithSteps(board, boardSize, boardColSize, word, curIndex+1, steps, curx+1, cury);
    }
    if (cury > 0 && steps[curx][cury-1] == 0 ) {
        //左
        find = find || existWithSteps(board, boardSize, boardColSize, word, curIndex+1, steps, curx, cury-1);
    }
    if (cury < boardColSize[curx] - 1 && steps[curx][cury+1] == 0 ) {
        //右
        find = find || existWithSteps(board, boardSize, boardColSize, word, curIndex+1, steps, curx, cury+1);
    }
    steps[curx][cury] = 0;
    return find;
}
