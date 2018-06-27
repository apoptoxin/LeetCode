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

其中curLength表示以当前为结尾的无重复子串长度，遍历的每次循环都是在计算这个长度，如果比totalLength大就更新到结果，最后totalLength就是所需的结果。代码复杂度![](http://chart.googleapis.com/chart?cht=tx&chl=O(n))

## p4 两个排序数组的中位数

基于二分的思想，取数组中间值进行比较，较小的为a数组，较大的为b数组

a数组中间值下标为lowMid，b数组中间值下标为highMid，这样就把题目转换成了从a，b两个数组中找第k大的元素。

去掉一些递归结束条件，核心判断如下：

- lowMid + 1 >= k 也就是a[0,lowMid]元素个数大于k，说明第k大的元素一定在a[0,lowMid]Ub[0,highMid)中。
- 否则
  - lowMid + 1 + highMid + 1 <=k ，也就是a[0,lowMid]以及b[0,highMid]总元素个数要小于等于k，那么第k个元素一定在a(lowMid,n)Ub[0,m)中，这样，就扔掉了a中的前lowmid+1个元素，所以，就在a(lowMid,n)Ub[0,m)中找第k-lowMid-1大的元素。
  - lowMid + 1 + highMid + 1 > k， 也就是a[0,lowMid]以及b[0,highMid]总元素个数要大于k，那么第k个元素一定在a[0,n)Ub[0,highMid)中，所以在a[0,n)Ub[0,highMid)中找第k大的元素即可。

```c
if (lowMid + 1 >= k) {
            return findKthSortedArrays(nums1, lowMid+1, nums2, highMid, k);
        } else {
            if (lowMid + 1 + highMid + 1 <=k) {
                return findKthSortedArrays(nums1+lowMid+1, nums1Size-lowMid-1, nums2, nums2Size, k-lowMid-1);
            } else {
                return findKthSortedArrays(nums1, nums1Size, nums2, highMid, k);
            }
        }
```



剩下的就是写一些结束条件，比如一个数组长度为0时，就从另一个数组找；如果一个数组长度为1，就二分另一个数组，与当前这个长度为1的数组的值比较，然后判断是直接返回还是丢弃一部分继续查找。

结束条件判断代码如下：

```c
if (nums1Size == 0) {
        return nums2[k-1];
    } else if (nums2Size == 0) {
        return nums1[k-1];
    } else if (nums1Size == 1 && nums2Size == 1) {
        if (nums1[0] < nums2[0]) {
            return k == 1 ? nums1[0] : nums2[0];
        } else {
            return k == 2 ? nums1[0] : nums2[0];
        }
    } else if (nums1Size == 1) {
        int mid = nums2Size / 2;
        if (nums2[mid] <= nums1[0]) {
            if (mid >= k-1) {
                return nums2[k-1];
            } else {
                return findKthSortedArrays(nums1, nums1Size, nums2+mid+1, nums2Size - mid - 1, k-mid-1);
            }
        } else {
            if (mid>k-2) {
                return findKthSortedArrays(nums1, nums1Size, nums2, mid, k);
            } else {
                return nums2[k-2];
            }
        }
    }
```



