//
//  problem71.c
//  LeetCode
//
//  Created by liunan on 2018/11/19.
//  Copyright © 2018 micronil.com. All rights reserved.
//

#include "problem71.h"

//规则 一个点表示当前，两个点表示上一级，三个点及以上就是名称了

enum State
{
    None, Slash, Dot, DoubleDot, DirName
};

char* simplifyPath(char* path) {
    enum State state = None;
    int totalLength = strlen(path);
    char * re = malloc(sizeof(char)*(totalLength+1));
    int curIndex = -1;
    
    for (int i = 0; i <totalLength; i++) {
        char curChar = path[i];
        switch (state) {
            case None:
            {
                if (curChar == '/' && curIndex == -1) {
                    re[++curIndex] = curChar;
                    state = Slash;
                } else {
                    return "/";
                }
            }
                break;
            case Slash:
            {
                if (curChar == '.') {
                    //斜杠后面跟一个点
                    state = Dot;
                } else if (curChar != '/') {
                    //斜杠后面跟一个字母
                    do {
                        re[++curIndex] = path[i++];
                    } while (path[i] != '/' && i < totalLength);
                    i--;
                    state = DirName;
                }
            }
                break;
            case Dot:
            {
                if (path[i] == '.') {
                    state = DoubleDot;
                } else if (path[i] == '/') {
                    state = Slash;
                } else {
                    //一个点后面直接跟字母
                    re[++curIndex] = '.';
                    do {
                        re[++curIndex] = path[i++];
                    } while (path[i] != '/' && i < totalLength);
                    i--;
                    state = DirName;
                }
            }
                break;
            case DoubleDot:
            {
                if (path[i] == '/') {
                    int first = 0;
                    while (curIndex > 0 && (first == 0 || re[curIndex] != '/')) {
                        first = 1;
                        curIndex--;
                    }
                    state = Slash;
                } else {
                    //两个点后面跟字母或者点
                    int pos = i+1;
                    while (pos < totalLength && path[i] != '/') {
                        pos++;
                    }
                    if (pos == totalLength) {
                        //后面全是点
                        i = i-2;
                        do {
                            re[++curIndex] = path[i++];
                        } while ( i < totalLength);
                        state = DirName;
                    }
                }
            }
                break;
            case DirName:
            {
                if (path[i] == '/') {
                    re[++curIndex] = '/';
                    state = Slash;
                } else {
                    return "/";
                }
            }
                break;
            default:
                break;
        }
        
    }
    if (state == DoubleDot) {
        int first = 0;
        while (curIndex > 0 && (first == 0 || re[curIndex] != '/')) {
            first = 1;
            curIndex--;
        }
    }
    while (curIndex > 0 && re[curIndex] == '/') {
        curIndex--;
    }
    re[++curIndex] = '\0';
    return re;
}

