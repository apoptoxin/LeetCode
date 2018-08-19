//
//  problem44.c
//  LeetCode
//
//  Created by 刘楠 on 2018/8/19.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem44.h"

void contructTable(int **table, char* s, char* p) {
    int slen = strlen(s);
    int plen = strlen(p);
    for (int i = 0 ; i < slen; i++) {
        for (int j = 0 ; j < plen; j++) {
            if (p[j] == '*') {
                if (i == 0 && j == 0) {
                    table[i][j] = true;
                } else if(i == 0){
                    table[i][j] = table[i][j-1];
                } else if(j == 0){
                    table[i][j] = true;
                } else {
                    table[i][j] = table[i-1][j-1] || /*匹配多个*/table[i][j-1] || /*匹配0个*/table[i-1][j];
                }
            } else {
                if (i == 0 && j == 0) {
                    table[i][j] = (s[i] == p[j] || p[j] == '?');
                } else if(i == 0){
                    if (p[j-1] == '*') {
                        //有去重，所以j-2不可能为*
                        if (j == 1) {
                            table[i][j] = (s[i] == p[j] || p[j] == '?');
                        } else {
                            table[i][j] = false;
                        }
                    } else {
                        table[i][j] = false;
                    }
                } else if(i == 0 || j == 0){
                    table[i][j] = false;
                } else {
                    table[i][j] = table[i-1][j-1] && (s[i] == p[j] || p[j] == '?');
                }
            }
        }
    }
}

bool isMatch44(char* s, char* p) {
    char *newp = malloc(sizeof(char) * (strlen(p) + 1));
    int pos = 0;
    int plen = strlen(p);
    int slen = strlen(s);
    for (int i = 0; i < plen; i++) {
        if (pos > 0 && newp[pos - 1] == '*' && p[i] == '*') {
            continue;
        } else {
            newp[pos++] = p[i];
        }
    }
    newp[pos] = '\0';
    if (slen == 0 && (pos == 0 || (pos == 1 && newp[0]=='*'))) {
        return true;
    }
    if (slen == 0) {
        return false;
    }
    int **table = malloc(sizeof(int*) * strlen(s));
    for (int i = 0 ; i < slen; i++) {
        int *t = malloc(sizeof(int) * pos);
        // for (int j = 0 ; j < strlen(newp); j++) {
        //     t[j] = -1;
        // }
        table[i] = t;
    }
    contructTable(table,s, newp);
    // for (int i = 0 ; i < strlen(s); i++) {
    //     for (int j = 0 ; j < strlen(newp); j++) {
    //         printf("%d ",table[i][j]);
    //     }
    //     printf("\n");
    // }
    return table[slen-1][pos-1];
}

bool isMatch_better(char* s, char* p) {
    if (s == NULL && p == NULL)
        return true;
    
    int m = strlen(s);
    int n = strlen(p);
    if (m == 0 && n == 0)   return true;
    int si = 0, pi = 0;
    int xidx = -1, mtch = -1;
    while (si < m) {
        if (pi < n && (*(p + pi) == '*'))
        {
            xidx = pi++;
            mtch = si;
        }
        else if (pi < n && (*(s + si) == *(p + pi) || *(p + pi) == '?'))
        {
            ++si;
            ++pi;
        }
        else if (xidx > -1) {
            pi = xidx + 1;
            si = ++mtch;
        }
        else {
            return false;
        }
    }
    while (pi < n && (*(p + pi) == '*'))
    {
        ++pi;
    }
    return (pi == n);
}
