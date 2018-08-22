//
//  problem40.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/14.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem40.h"
#include <stdlib.h>

int cmpfunc40 (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int total = 0;
    int **result = malloc(sizeof(int*));
    int *columnSize = malloc(sizeof(int));
    int columnSizeCount = 0;
    int *tmp = malloc(sizeof(int) * target);//用于记录暂存的数值下标
    int pos = -1;
    qsort(candidates, candidatesSize, sizeof(int), cmpfunc40);
    int axis = 0;
    int curTarget = target;
    while (pos >= 0 || axis < candidatesSize) {
        ////////////////
        printf("tmp:");
        for (int i = 0 ; i <= pos ; i++) {
            printf("%d ",candidates[tmp[i]]);
        }
        printf("\r\npos:%d curAxisVal:%d curTar:%d\n\r",pos,candidates[axis],curTarget);
        ////////////////
        if (curTarget <= 0 || axis > candidatesSize) {
            if (curTarget == 0 && axis <= candidatesSize) {
                int *out = malloc(sizeof(int) * (pos+1));
                for (int i = 0 ; i <= pos; i++) {
                    out[i] = candidates[tmp[i]];
                }
                if (total == 0) {
                    result = malloc(sizeof(int *));
                    
                    result[0] = out;
                } else {
                    result = realloc(result,sizeof(int*)*(total+1));
                    result[total] = out;
                }
                if (columnSizeCount == 0) {
                    columnSize = malloc(sizeof(int));
                } else {
                    columnSize = realloc(columnSize, sizeof(int) * (columnSizeCount+1));
                }
                columnSize[columnSizeCount] = pos + 1;
                columnSizeCount++;
                total++;
            }
            //回滚最后一位
            curTarget += candidates[tmp[pos]];
            axis = tmp[pos] + 1;
            while (axis >= 1 && candidates[axis] == candidates[axis-1]) {
                axis++;
            }
            pos--;
            while (axis >= candidatesSize && pos >= 0) {
                curTarget += candidates[tmp[pos]];
                axis = tmp[pos] + 1;
                while (axis >= 1 && candidates[axis] == candidates[axis-1]) {
                    axis++;
                }
                pos--;
            }
        } else {
            tmp[++pos] = axis;
            curTarget -= candidates[axis];
            axis++;
        }
    }
    if (returnSize) {
        *returnSize = total;
    }
    if (columnSizes) {
        *columnSizes = columnSize;
    }
    return result;
}

//class Solution {
//public:
//    void dfs(vector<int>& candidates, int target, vector<vector<int>> &re, vector<int> &temp, int sum, int index){
//        if (sum > target)  return;//减支
//        if (sum == target) {
//            re.push_back(temp);
//            return;
//        }
//
//        for (int i = index + 1; i < candidates.size(); ++i){//从这个数的后面开始进行搜索
//            if (i != index + 1 && candidates[i] == candidates[i - 1]) continue;//同一层中，后面的数和前面相同的时候，会出现重复，直接continue。
//            temp.push_back(candidates[i]);
//            dfs(candidates, target, re, temp, sum + candidates[i], i);
//            temp.pop_back();
//        }
//    }
//
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        sort(candidates.begin(), candidates.end());//排序，方便后来减支
//        vector<vector<int>> re;
//        vector<int> temp;
//        dfs(candidates, target, re, temp, 0, -1);
//        return re;
//    }
//};

