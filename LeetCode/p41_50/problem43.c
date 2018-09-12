//
//  problem43.c
//  LeetCode
//
//  Created by apoptoxin on 2018/8/16.
//  Copyright © 2018年 micronil.com. All rights reserved.
//

#include "problem43.h"

struct NumNode {
    int val;
    struct NumNode * next;
};

struct NumNode* multiplyWithSingleNum(struct NumNode* num1,int mul,int zeroCount) {
    if (mul == 0) {
        struct NumNode *c = malloc(sizeof(struct NumNode));
        c->val = 0;
        c->next = NULL;
        return c;
    }
    int add = 0;
    struct NumNode *head = NULL;
    struct NumNode *tmp = NULL;
    for (int i = 0 ; i < zeroCount ; i++) {
        struct NumNode *c = malloc(sizeof(struct NumNode));
        c->val = 0;
        c->next = NULL;
        if (head == NULL) {
            head = c;
            tmp = c;
        } else {
            tmp->next = c;
            tmp = c;
        }
    }
    while (num1 != NULL || add > 0) {
        int cur = num1==NULL ? add : num1->val * mul + add;
        struct NumNode *c = malloc(sizeof(struct NumNode));
        c->val = cur%10;
        c->next = NULL;
        if (head == NULL) {
            head = c;
            tmp = c;
        } else {
            tmp->next = c;
            tmp = c;
        }
        add = cur/10;
        if (num1!= NULL) {
            num1 = num1->next;
        }
    }
    return head;
}

struct NumNode* addition(struct NumNode *num1, struct NumNode *num2, int *length) {
    int total = 0;
    int add = 0;
    struct NumNode *head = NULL;
    struct NumNode *tmp = NULL;
    while (num1 != NULL || num2 != NULL || add > 0) {
        int cur = (num1== NULL ? 0 :num1->val) + (num2==NULL?0:num2->val) + add;
        struct NumNode *c = malloc(sizeof(struct NumNode));
        c->val = cur%10;
        c->next = NULL;
        if (head == NULL) {
            head = c;
            tmp = c;
        } else {
            tmp->next = c;
            tmp = c;
        }
        total++;
        add = cur/10;
        if (num1 != NULL) {
            num1 = num1->next;
        }
        if (num2 != NULL) {
            num2 = num2->next;
        }
    }
    if (length) {
        *length = total;
    }
    return head;
}

char* multiply(char* num1, char* num2) {
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    if (length1 <= 0 || length2 <= 0) {
        return NULL;
    }
    if ((length1 == 1 && num1[0] == '0') || (length2 == 1 && num2[0] == '0')) {
        char *s = malloc(sizeof(char)*2);
        s[0] = '0';
        s[1] = '\0';
        return s;
    }
    struct NumNode *num1Head = NULL;
    struct NumNode *num2Head = NULL;
    for (int i = 0 ; i < length1; i++) {
        int t = num1[i] - '0';
        struct NumNode * node = malloc(sizeof(struct NumNode));
        node->val = t;
        node->next = num1Head;
        num1Head = node;
    }
    for (int i = 0 ; i < length2; i++) {
        int t = num2[i] - '0';
        struct NumNode * node = malloc(sizeof(struct NumNode));
        node->val = t;
        node->next = num2Head;
        num2Head = node;
    }
    struct NumNode *last = NULL;
    int totalLength = 0;
    for (int i = 0 ; i < length2 ; i++) {
        struct NumNode *cur = multiplyWithSingleNum(num1Head, num2Head->val,i);
        last = addition(cur, last, &totalLength);
        num2Head = num2Head->next;
    }
    char *s = malloc(sizeof(char)*(totalLength+1));
    s[totalLength] = '\0';
    for (int i = totalLength - 1 ; i >= 0 ; i--) {
        s[i] = '0' + last->val;
        last = last->next;
    }
    return s;
}
