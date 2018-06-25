## p1 两数之和

### 方法1

两层for循环遍历（暴力法）

### 方法2

哈希表，具体方法是，遍历，每读到一个元素时，当前值，target值，差值都是可知的。首先判断差值是否在hash表中，如果在，那么当前值和差值就是我们要找的两个值了，返回下标即可；如果差值不在，那么将<当前值，下标>放入hashmap中。

## p2 两数相加

数学知识，注意进位就可以。

```c
struct ListNode* addTwoNumberWithAddition(struct ListNode *l1, struct ListNode *l2,int addition)
{
    if (l1 == NULL && l2 == NULL && addition == 0) {
        return NULL;
    }
    //cal current
    struct ListNode* cur = malloc(sizeof(struct ListNode));
    int l1Val = (l1 == NULL) ? 0 : l1->val;
    int l2Val = (l2 == NULL) ? 0 : l2->val;
    int total = l1Val + l2Val + addition;
    cur->val = total % 10;
    cur->next = addTwoNumberWithAddition(l1 == NULL?NULL:l1->next, l2 == NULL ? NULL : l2->next, total / 10);
    return cur;
}
```

## p3 无重复字符的最长子串

声明int map[128] 用于记录，下标对应的是char转int的值，map元素的值对应的是该char在字符串中的第几个。核心代码为

```c
for (int i = 0, curLength = 0; i < len ; i++) {
        int pos = s[i];
        if (map[pos] == -1 || i - map[pos] > curLength) {
            curLength ++;
            if (curLength > totalLength) {
                totalLength = curLength;
            }
        } else {
            curLength = i - map[pos];
        }
        map[pos] = i;
    }
```

其中curLength表示以当前为结尾的无重复子串长度，遍历的每次循环都是在计算这个长度，如果比totalLength大就更新到结果，最后totalLength就是所需的结果。代码复杂度为
$O(n)$
