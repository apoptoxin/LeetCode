//
//  problem74.c
//  LeetCode
//
//  Created by liunan on 2019/6/2.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem74.h"

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    //二分找行
    if (matrixSize <= 0 || matrixColSize[0] <= 0) {
        return false;
    }
    int start = 0;
    int end = matrixSize - 1;
    int middle = (end-start)*0.5+start;
    while (start < end) {
        middle = (end-start)*0.5+start;
        if (matrix[middle][0] < target) {
            start = middle + 1;
        } else if ( matrix[middle][0] > target) {
            end = middle - 1;
        } else {
            return true;
        }
    }
    int xPos = (matrix[start][0] > target && start - 1 >= 0) ? start - 1 : start;
    //在xPos行二分找列
    start = 0;
    end = matrixColSize[xPos] - 1;
    middle = (end-start)*0.5+start;
    while (start < end) {
        middle = (end-start)*0.5+start;
        if (matrix[xPos][middle] < target) {
            start = middle + 1;
        } else if ( matrix[xPos][middle] > target) {
            end = middle - 1;
        } else {
            return true;
        }
    }
    return matrix[xPos][start] == target;
}
