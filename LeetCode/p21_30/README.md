## p21 合并两个有序链表
每次找两个链表中较小的那个，最终组成一个链表就可以了
```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode *cur = NULL;
    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            //进入循环条件是l1 或者 l2至少有一个不为空，所以l1为空的话l2一定不为空
            if (head == NULL) {
                head = cur = l2;
            } else {
                cur->next = l2;
                cur = cur->next;
            }
            l2 = l2->next;
        } else if (l2 == NULL) {
            if (head == NULL) {
                head = cur = l1;
            } else {
                cur->next = l1;
                cur = cur->next;
            }
            l1 = l1->next;
        } else {
            if (l1->val < l2->val) {
                if (head == NULL) {
                    head = cur = l1;
                } else {
                    cur->next = l1;
                    cur = cur->next;
                }
                l1 = l1->next;
            } else {
                if (head == NULL) {
                    head = cur = l2;
                } else {
                    cur->next = l2;
                    cur = cur->next;
                }
                l2 = l2->next;
            }
        }
    }
    return head;
}
```
写法不是很好

## p22 括号生成
递归做就好了，根据前面有几个左括号判断，下一个加左括号或者右括号，具体看代码
```c
char** generateParenthesisWithLeftAndRightCount(char* prefix, int left, int right, int n ,int* returnSize) {
    int prefixLength = (int)strlen(prefix);
    int count = 0;
    char** result = NULL;
    if (left == right && left == n) {
        if (strlen(prefix) > 0) {
            result = (char**)malloc(sizeof(char*));
            result[0] = prefix;
            *returnSize += 1;
        }
        return result;
    }
    if (n-left>0) {
        char *tmp = malloc(sizeof(char) *(prefixLength+2));
        strcpy(tmp,prefix);
        tmp[prefixLength] = '(';
        tmp[prefixLength+1] = '\0';
        result = generateParenthesisWithLeftAndRightCount(tmp, left+1, right, n, &count);
    }
    if(right<left) {
        char *tmp = malloc(sizeof(char) *(prefixLength+2));
        strcpy(tmp,prefix);
        tmp[prefixLength] = ')';
        tmp[prefixLength+1] = '\0';
        int tmpCount = 0;
        char **tmpRight = generateParenthesisWithLeftAndRightCount(tmp, left, right+1, n, &tmpCount);
        result = realloc(result, (count+tmpCount) * sizeof(char*));
        for (int i = 0; i < tmpCount ; i++) {
            result[count+i] = tmpRight[i];
        }
        count += tmpCount;
    }
    *returnSize += count;
    return result;
}
```

## p23 合并k个排序链表
方法1 ：每次找k个链表中最小的，循环遍历直到所有节点都遍历到
方法2 ：每次合并两个链表，调用p21里的函数就好
