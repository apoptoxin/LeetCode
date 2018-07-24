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

## p24 两两交换链表中的节点
感觉链表的问题，主要就是记录对应节点
这里，trim表示已经完成交换倒数第二个（可能有人问为什么是倒数第二个，其实倒数第一个也可以，只是我当时写代码写成这样也懒得改了），first表示需要交换的第一个节点，second表示第二个。代码如下:
```c
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *trim = NULL;
    struct ListNode *newHead = NULL;
    struct ListNode *first = NULL;
    struct ListNode *second = NULL;
    while (head != NULL) {
        first = head;
        second = head->next;
        head = second;
        if (head!=NULL) {
            head = head->next;
            //这里head就应该指向second的下一个了
        }
        if (second == NULL) {
            //只有一个元素，不用交换
            if (newHead == NULL) {
                newHead = first;
            }
        } else {
            //交换first和second
            //当前trim应该指向NULL或者first的前两个
            second->next = first;
            first->next = head;
            if (trim == NULL) {
                trim = second;
                newHead = trim;
            } else {
                trim->next->next = second;
                trim = second;
            }
        }
    }
    return newHead;
}
```
感觉应该有比这更简洁的写法，但是时间复杂度没有本质变化，额外空间也都是常数大小，所以懒得搞了\~

## p25 k个一组翻转链表
和上一题比较相似吧，只不过把2个一组扩展到k个，如果先做这一题感觉更好，更通用，上一题的写法单纯只能完成上一题的要求没法扩展。思路差不多，就不多说，直接上代码吧。
```c
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *newHead = NULL;
    struct ListNode *trim = NULL;//指向first的上一个
    struct ListNode *first = NULL;
    struct ListNode *end = NULL;
    struct ListNode *tmps = NULL;//临时指针,start
    struct ListNode *tmpe = NULL;//临时指针,end
    struct ListNode *tmp = NULL;
    while (head != NULL) {
        first = head;
        int i = 0;
        for (; i < k && head != NULL; i++) {
            end = head;
            head = head->next;
        }
        if (i < k) {
            if (trim == NULL) {
                newHead = first;
            }
            break;
        }
        //这里first指向要交换的第一个，end指向最后一个,head指向end的下一个
        tmps = first;
        tmpe = first->next;
        tmp = NULL;
        first->next = NULL;
        while (tmps!=end && tmpe!=NULL) {
            tmps->next = tmp;
            tmp = tmps;
            tmps = tmpe;
            tmpe = tmpe->next;
        }
        if (tmps == end) {
            tmps->next = tmp;
        }
        if (trim == NULL) {
            trim = first;
            newHead = end;
        } else {
            trim->next = end;
            trim = first;
        }
        first->next = head;
    }
    return newHead;
}
```

