//
//  problem68.c
//  LeetCode
//
//  Created by liunan on 2018/11/7.
//  Copyright © 2018 micronil.com. All rights reserved.
//

#include "problem68.h"
#include "bool_define.h"

char* justifySingleLine(char** words, int startPos, int endPos, int maxWidth, bool isLastLine);

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int totalSize = 0;
    char ** re = malloc(sizeof(char *) * wordsSize);
    for (int i = 0, curLen = 0, start = 0; i <= wordsSize; i++) {
        if (i == wordsSize) {
            //从start 到 i-1
            re[totalSize++] = justifySingleLine(words, start, i-1, maxWidth, true);
        } else {
            curLen += strlen(words[i]);
            if (curLen > maxWidth) {
                //从start 到 i-1
                re[totalSize++] = justifySingleLine(words, start, i-1, maxWidth, false);
                curLen = strlen(words[i]) + 1;
                start = i;
            } else {
                curLen += 1;//加一个空格
            }
        }
    }
    if (returnSize) {
        *returnSize = totalSize;
    }
    return re;
}

char* justifySingleLine(char** words, int startPos, int endPos, int maxWidth, bool isLastLine) {
    char *re = malloc(sizeof(char) * (maxWidth+1));
    re[maxWidth] = '\0';
    int cur = 0;
    if (!isLastLine) {
        int wordLength = 0;
        for (int i = startPos; i <= endPos; i++) {
            wordLength += strlen(words[i]);
        }
        int totalSpace = maxWidth - wordLength;
        int spaceCount = endPos - startPos;
        int base = spaceCount <= 0 ? totalSpace : totalSpace / spaceCount;
        int addCount = spaceCount <= 0 ? 0 : totalSpace % spaceCount;
        for (int i = startPos; i <= endPos; i++) {
            char* curWord = words[i];
            int curTotal = strlen(curWord);
            for (int j = 0 ; j < curTotal; j++,cur++) {
                re[cur] = curWord[j];
            }
            if (i != endPos) {
                int add = i - startPos < addCount ? 1 : 0;
                for (int j = 0 ; j < base+add; j++, cur++) {
                    re[cur] = ' ';
                }
            }
        }
        for (; cur < maxWidth; cur++) {
            re[cur] = ' ';
        }
    } else {
        for (int i = startPos; i <= endPos; i++) {
            char* curWord = words[i];
            int curTotal = strlen(curWord);
            for (int j = 0 ; j < curTotal; j++,cur++) {
                re[cur] = curWord[j];
            }
            if (i != endPos) {
                re[cur++] = ' ';
            }
        }
        for (; cur < maxWidth; cur++) {
            re[cur] = ' ';
        }
    }
    return re;
}
