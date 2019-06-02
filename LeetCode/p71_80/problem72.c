//
//  problem72.c
//  LeetCode
//
//  Created by liunan on 2019/5/29.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem72.h"
#include <limits.h>

int minDistance(char * word1, char * word2) {
    int xTotal = strlen(word1);
    int yTotal = strlen(word2);
    if (xTotal <= 0) {
        return yTotal;
    } else if (yTotal <= 0) {
        return xTotal;
    }
    int **dis = malloc(sizeof(int *) * xTotal);
    for (int i = 0 ; i < xTotal; i++) {
        dis[i] = malloc(sizeof(int) * yTotal);
    }
    for (int x = 0 ; x < xTotal; x++) {
        for (int y = 0; y < yTotal; y++) {
            if (x == 0 && y == 0) {
                dis[0][0] = word1[0] == word2[0] ? 0 : 1;
            } else {
                int cur = INT_MAX;
                if (x == 0) {
                    int temp = word2[y] == word1[0] ? y : y+1;
                    temp = dis[x][y-1] + 1 > temp ? temp : dis[x][y-1] + 1;
                    cur = cur > temp ? temp : cur;
                } else if (y == 0) {
                    int temp = word2[0] == word1[x] ? x : x+1;
                    temp = dis[x-1][y] + 1 > temp ? temp : dis[x-1][y] + 1;
                    cur = cur > temp ? temp : cur;
                } else if (x > 0 && y > 0) {
                    int temp = dis[x-1][y-1];
                    temp += word1[x] == word2[y] ? 0: 1;
                    temp = dis[x-1][y] + 1 > temp ? temp : dis[x-1][y] + 1;
                    temp = dis[x][y-1] + 1 > temp ? temp : dis[x][y-1] + 1;
                    cur = cur > temp ? temp : cur;
                }
                dis[x][y] = cur;
            }
        }
    }
    for (int i = 0 ; i < xTotal; i++) {
        for (int j = 0 ; j < yTotal; j++) {
            printf("%d ",dis[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return dis[xTotal-1][yTotal-1];
}

//动态规划
// f(x,y)=f(x-1,y)+1插入，f(x,y-1)+1删除,f(x-1,y-1)+word1[x]==word[y]?0:1 修改
// 边界条件是x==0或者y==0
