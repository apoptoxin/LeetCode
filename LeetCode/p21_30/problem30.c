//
//  problem30.c
//  LeetCode
//
//  Created by apoptoxin on 2018/7/31.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem30.h"
#include "kmp.h"
#include "bool_define.h"

struct IndexNode {
    int startIndex;
    int len;
    struct IndexNode *next;
};

struct IndexNode * findAllIndexForSubstring(char *s, int cur, char *word);
bool canFix(struct IndexNode ** array, int arrayCount, int target);

int* findSubstringFucOne(char* s, char** words, int wordsSize, int* returnSize) {
    int *result = NULL;
    int total = 0;
    struct IndexNode **nodes = malloc(sizeof(struct IndexNode *) * wordsSize);
    for (int i = 0 ; i < wordsSize ; i++) {
        nodes[i] = findAllIndexForSubstring(s, 0, words[i]);
    }
    
    for (bool con = true; con; ) {
        int index = -1;
        con = false;
        for (int i = 0 ; i < wordsSize; i++) {
            if (nodes[i] == NULL) {
                break;
            }
            if (index < 0 || nodes[i]->startIndex < nodes[index]->startIndex) {
                con = true;
                index = i;
            }
        }
        //找到最小的一个
        if (con) {
            if (canFix(nodes, wordsSize, nodes[index]->startIndex)) {
//                printf("%d  ",nodes[index]->startIndex);
                if (result == NULL) {
                    result = malloc(sizeof(int));
                    result[0] = nodes[index]->startIndex;
                    total++;
                } else if(nodes[index]->startIndex != result[total-1]) {
                    result = realloc(result,(total+1) * sizeof(int));
                    result[total] = nodes[index]->startIndex;
                    total++;
                }
            }
            nodes[index] = nodes[index]->next;
        }
    }
    
    if (returnSize) {
        *returnSize = total;
    }
    return result;
}


struct IndexNode * findAllIndexForSubstring(char *s, int cur, char *word) {
    if (strlen(s) == 0 || strlen(word) == 0) {
        return NULL;
    }
    int index = kmpSearch(s, word);
    if (index < 0) {
        return NULL;
    } else {
        struct IndexNode *node = malloc(sizeof(struct IndexNode));
        node->startIndex = cur+index;
        node->len = strlen(word);
        node->next = findAllIndexForSubstring(s+index+1, cur+index+1, word);
        return node;
    }
}

int findTargetInArray(struct IndexNode ** array, int arrayCount, int target) {
    int result = -1;
    for (int i = 0 ; i < arrayCount ; i++) {
        struct IndexNode *cur = array[i];
        while (cur!= NULL) {
            if (cur->startIndex == target) {
                result = i;
                break;
            }
            cur = cur->next;
        }
        if (result >= 0) {
            break;
        }
    }
    
    return result;
}

bool canFix(struct IndexNode ** array, int arrayCount, int target) {
    if (arrayCount <= 0) {
        return true;
    }
    struct IndexNode *find = NULL;
    bool result = false;
    for (int i = 0 ; i < arrayCount ; i++) {
        struct IndexNode *cur = array[i];
        while (cur!= NULL) {
            if (cur->startIndex == target) {
                find = array[i];
                break;
            }
            cur = cur->next;
        }
        if (find != NULL) {
            struct IndexNode ** tmp = malloc(sizeof(struct IndexNode *) * (arrayCount - 1));
            for (int i = 0 ,cur = 0; i < arrayCount; i++) {
                if (array[i] != find) {
                    tmp[cur] = array[i];
                    cur++;
                }
            }
            result = canFix(tmp, arrayCount-1, target+find->len);
        }
    }
    return result;
}

int* findSubstringFuncTwo(char* s, char** words, int wordsSize, int* returnSize);
/////////////////////////////// 主函数 /////////////////////////////////////////
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    return findSubstringFuncTwo(s, words, wordsSize, returnSize);
}
/////////////////////////////// 第二个解法 /////////////////////////////////////////

struct InfoRecord {
    char *key;
    int count;
};

int* findSubstringFuncTwo(char* s, char** words, int wordsSize, int* returnSize) {
    if (strlen(s) == 0 || wordsSize == 0 || strlen(s) < strlen(words[0]) * wordsSize) {
        if (returnSize) {
            *returnSize = 0;
        }
        return 0;
    }
    struct InfoRecord tmp[wordsSize];
    int totalStrLength = strlen(s);
    int singleWordLength;
    int realWordsSize = 0;
    int totalWordsLength = 0;
    
    for (int i = 0 ; i < wordsSize; i++) {
        singleWordLength = strlen(words[i]);
        totalWordsLength += singleWordLength;
        bool find = false;
        for (int j = 0; j < realWordsSize; j++) {
            if (strcmp(tmp[j].key, words[i]) == 0) {
                find = true;
                tmp[j].count++;
            }
        }
        if (!find) {
            struct InfoRecord t = {.key=words[i],.count=1};
            tmp[realWordsSize++] = t;
        }
    }
    
    //本身是应该用map的，c语言写的比较费劲，就降级用数组来查找~
    int *curCount = malloc(sizeof(int) * realWordsSize);
    for (int i = 0; i < realWordsSize; i++) {
        curCount[i] = 0;
    }
    
    int *mapCount = malloc(sizeof(int) * realWordsSize);
    for (int i = 0; i < realWordsSize; i++) {
        mapCount[i] = tmp[i].count;
    }
    
    int *re = 0;
    int totalResultCount = 0;
    
    for (int start = 0 ; start < totalStrLength - totalWordsLength + 1; start++) {
        int end = start;
        while (end < start + totalWordsLength) {
            char *substr = malloc(sizeof(char) *(singleWordLength+1));
            for (int k = 0; k<singleWordLength; k++) {
                substr[k] = s[end+k];
            }
            substr[singleWordLength] = '\0';
            
            int index = -1;
            for (int k = 0; k < realWordsSize; k++) {
                if (strcmp(tmp[k].key, substr) == 0) {
                    index = k;
                }
            }
            if (index >= 0) {
                curCount[index] ++;
                if (curCount[index] > mapCount[index]) {
                    break;
                }
            } else {
                break;
            }
            end += singleWordLength;
        }
        if (end == start + totalWordsLength) {
            if (totalResultCount == 0) {
                re = malloc(sizeof(int));
                re[0] = start;
                totalResultCount ++;
            } else {
                ++totalResultCount;
                re = realloc(re, totalResultCount*sizeof(int));
                re[totalResultCount-1] = start;
            }
        }
        for (int k = 0 ; k < realWordsSize; k++) {
            curCount[k]=0;
        }
    }
    
    if (returnSize) {
        *returnSize = totalResultCount;
    }
    return re;
}
