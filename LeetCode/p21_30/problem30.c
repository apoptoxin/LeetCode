//
//  problem30.c
//  LeetCode
//
//  Created by 刘楠 on 2018/7/31.
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

/////////////////////////////// 主函数 /////////////////////////////////////////
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    return findSubstringFucOne(s, words, wordsSize, returnSize);
}
/////////////////////////////// 第二个解法 /////////////////////////////////////////

//int* findSubstringFuncTwo(char* s, char** words, int wordsSize, int* returnSize) {
//    
//}
