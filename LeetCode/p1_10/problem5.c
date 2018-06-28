//
//  problem5.c
//  LeetCode
//
//  Created by 刘楠 on 2018/6/27.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem5.h"

char* longestPalindrome(char* s) {
    /*
     * 写一下自己的思路，虽然最后编码是借鉴答案里的方法
     * 自己思路：也是动态规划，但没规划明白
     * f(x,y)表示以x为轴，y为结尾的子串长度，这个地方理解是有问题的
     * 参考题解，函数的含义定义为f(x,y)表示从x开始到y的子串为回文
     * 则f(x,y)=f(x+1,y-1) && s[x] == s[y]
     */
    int totalLen = strlen(s);
    int map[totalLen][totalLen];
    for (int x = totalLen - 1; x >= 0; x--) {
        for (int y = x; y < totalLen; y++) {
            if (x == y) {
                map[x][y] = 1;
            } else if(x+1==y) {
                if (s[x] == s[y]) {
                    map[x][y] = 1;
                } else {
                    map[x][y] = 0;
                }
            } else {
                map[x][y] = map[x+1][y-1] && s[x] == s[y] ;
            }
        }
    }
    int maxStart = 0;
    int maxLen = 0;
    for (int x = 0; x < totalLen; x++) {
        for (int y = x; y < totalLen; y++) {
            if (map[x][y] == 1) {
                if (y-x+1 > maxLen) {
                    maxLen = y-x+1;
                    maxStart = x;
                }
            }
        }
    }
    char *re = malloc(sizeof(char) * (maxLen+1));
    for (int i = 0; i<maxLen; i++) {
        re[i] = s[maxStart+i];
    }
    re[maxLen] = '\0';
    return re;
}
