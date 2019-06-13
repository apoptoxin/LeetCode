//
//  problem76.c
//  LeetCode
//
//  Created by liunan on 2019/6/3.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem76.h"

int getPositionInArray(char s) {
    return s;
}

char * minWindow(char * s, char * t){
    int t_len = strlen(t);
    int s_len = strlen(s);
    if (t_len <= 0 || t_len > s_len) {
        return "";
    }
    //初始化
    int target[65535] = {0};
    int cur_count[65535] = {0};
    int total_find_count = 0;
    for (int i = 0 ; i < t_len; i++) {
        target[getPositionInArray(t[i])]++;
        total_find_count++;
    }
    //双指针，找
    int re_start = -1;
    int re_len = 0;
    int start = 0;
    int end = 0;
    int step = 1;//表示上一步是走的end还是start,1表示end，0表示start
    while (start < s_len && end < s_len) {
        //每次走一个
        if (step == 1) {
            cur_count[getPositionInArray(s[end])]++;
            if (target[getPositionInArray(s[end])] > 0) {
                //有效的
                if (total_find_count > 0) {
                    if (cur_count[getPositionInArray(s[end])] <= target[getPositionInArray(s[end])]) {
                        total_find_count--;
                    }
                    step = total_find_count > 0 ? 1 : 0;
                } else {
                    //更新结果
                    if (cur_count[getPositionInArray(s[end])] >= target[getPositionInArray(s[end])]) {
                        step = 0;
                    } else {
                        step = 1;
                    }
                }
            } else {
                step = 1;
            }
        } else {
            //start向后走1
            cur_count[getPositionInArray(s[start-1])]--;
            if (target[getPositionInArray(s[start-1])] > 0) {
                //有效的
                if (cur_count[getPositionInArray(s[start-1])] < target[getPositionInArray(s[start-1])]) {
                    total_find_count++;
                    step=1;
                } else {
                    //更新结果
                    step = 0;
                }
            } else {
                step = 0;
            }
        }
        if (total_find_count == 0) {
            if (re_start < 0 || end - start < re_len) {
                re_start = start;
                re_len = end - re_start + 1;
            }
        }
        printf("当前start:%d,end:%d,count:%d,下一步：%s后移\n",start,end,total_find_count,step==1?"end":"start");
        if (end < s_len - 1 && step > 0) {
            step = 1;
            end++;
        } else {
            step = 0;
            start++;
        }
    }
    if (re_start < 0 || re_len <= 0) {
        return "";
    } else {
        char* re = malloc(sizeof(char)*(re_len+1));
        re[re_len] = '\0';
        for (int i = 0; i < re_len; i++) {
            re[i] = s[re_start+i];
        }
        return re;
    }
}
