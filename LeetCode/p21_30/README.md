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

## p26 删除排序数组中的重复项

用两个变量，一个用与指向当前下标，一个用于指向最后一个不重复元素的下标
```c
int removeDuplicates(int* nums, int numsSize) {
    int total = 0;
    int cur = -1;
    for (int i = 0 ; i < numsSize; i++) {
        if (cur < 0 || nums[i] != nums[cur]) {
            nums[++cur] = nums[i];
            total++;
        }
    }
    return total;
}
```

## p27 移除元素
和26题思路基本一致，只是判断条件稍有不同
```c
int removeElement(int* nums, int numsSize, int val) {
    int total = 0;
    int cur = -1;
    for (int i = 0 ; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[++cur] = nums[i];
            total++;
        }
    }
    return total;
}
```

## p28 实现strStr()
[KMP](https://blog.csdn.net/v_july_v/article/details/7041827)算法，有时间重新整理补齐一下

## p29 两数相除
题目是实现两数相除，不能使用乘法、除法和 mod 运算符。

那就只有加减，最简单的方法就是每次用被除数减去除数，重复，直到被除数小于除数。重复次数就是结果。

一种优化的方法是利用2分的思想，每次减去除数的2的n次幂，如果被除数比这个数要小，那么再与除数的2的n-1次幂比较。以此类推。
```c
int curDivide(int *dividend, int divisor,int times) {
    if (*dividend == 0) {
        return 0;
    } else if (*dividend > 0) {
        *dividend = 0-*dividend;
        return -curDivide(dividend, divisor, times);
    } else if (divisor > 0) {
        return -curDivide(dividend, -divisor, times);
    }
    
    //这里就都变成负数了
    int ori = *dividend;
    if (ori > divisor) {
        return 0;
    } else if (ori-divisor<=divisor) {
        int step1 = curDivide(dividend, divisor+divisor, times+times);
        int step2 = curDivide(dividend, divisor, times);
        return step1+step2;
    } else {
        *dividend = ori-divisor;
        return times;
    }
}

int divide(int dividend, int divisor) {
    
    int ori = dividend;
    //    本题中，如果除法结果溢出，则返回 231 − 1;这里只有dividend为最小值，divisor=-1时才可能
    if (ori == -2147483648 && divisor == -1) {
        return 2147483647;
    }
    return curDivide(&ori, divisor, 1);
}
```

## p30 与所有单词相关联的字串
我自己的思路是找到每个单词所有匹配的下标记成链表，然后每次取最小的下标，在这个链表中查找看是否能连上全部单词，但是这种思路内存超出限制了，应该可以优化暂时没有想到。

看到网上有一种[滑动窗口](https://blog.csdn.net/sty945/article/details/79846516)的解法,python解法[如下](https://github.com/sty945/leetcodePython/blob/master/Array/30.%20Substring%20with%20Concatenation%20of%20All%20Words.py)

事实上这个题目出的有问题，描述中说所有单词长度都相同，但是例子中又不同，如果不同就很难搞。下面的解法是基于长度相同给出：

假设所有words的总长度为lw，每个单词长度为ls，那么从0开始，每次去判断s[0~lw]的子串是不是满足条件。（这个子串用p表示）

那么怎么判断p是否满足呢？从p的头部开始，取ls长度的子串，去判断是否在words中并且出现次数不超出words中出现的次数（因为words中单词可能是相同的）。如果超过或者words中就没有这个单词，匹配失败，如果匹配成功，使用滑动窗口的思想，向右滑动ls长，继续上述判断。

这样就得到了我们需要的结果。

c代码如下，因为c中没有map，就用遍历数组查找来降级，时间复杂度就因此稍大一点

```c
struct InfoRecord {
    char *key;
    int count;
};

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
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
```