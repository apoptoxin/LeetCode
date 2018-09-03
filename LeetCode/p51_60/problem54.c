//
//  problem54.c
//  LeetCode
//
//  Created by 刘楠 on 2018/9/3.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem54.h"

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int total = matrixRowSize * matrixColSize;
    int forward = 0;// 0 表示向右走，1表示向下走，2表示向左走，3表示向上走
    int rightEnd = matrixColSize - 1;
    int downEnd = matrixRowSize - 1;
    int leftEnd = 0;
    int upEnd = 1;
    
    int *result = malloc(sizeof(int) * total);
    int i = 0;
    int j = 0;
    for (int p = 0 ; p < total ; p++) {
        //把当前写入，根据方向判断下一个
        result[p] = matrix[i][j];
        if (forward == 0) {
            if (j == rightEnd) {
                forward = 1;//右转下
                if (i == downEnd) {
                    break;
                }
                rightEnd--;
                i++;
            } else {
                j++;
            }
        } else if (forward == 1) {
            if (i == downEnd) {
                forward = 2;//下转左
                if (j == leftEnd) {
                    break;
                }
                downEnd--;
                j--;
            } else {
                i++;
            }
        } else if (forward == 2) {
            if (j == leftEnd) {
                forward = 3;
                if (i == upEnd) {
                    break;
                }
                leftEnd++;
                i--;
            } else {
                j--;
            }
        } else {
            if (i == upEnd) {
                forward = 0;
                if (j == rightEnd) {
                    break;
                }
                upEnd++;
                j++;
            } else {
                i--;
            }
        }
    }
    return result;
}
