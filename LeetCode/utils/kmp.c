//
//  kmp.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/30.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "kmp.h"


int* getNext(char* p,int* size)
{
    int pLen = strlen(p);
    if (pLen <= 0) {
        *size = 0;
        return NULL;
    }
    int *next = malloc(sizeof(int) * pLen);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        //p[k]表示前缀，p[j]表示后缀
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
    *size = pLen;
    return next;
}

int kmpSearch(char* s, char* p)
{
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    int nextSize = 0;
    int *next = getNext(p, &nextSize);
    while (i < sLen && j < pLen)
    {
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
            //next[j]即为j所对应的next值
            j = next[j];
        }
    }
    if (j == pLen)
        return i - j;
    else
        return -1;
}
