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



## p5 最长回文子串

想了很久，本以为能找到小于O(n2）的，但最后研究了半天还是没找到，下面列几个方法：

1. O(n2)方法，遍历两次，以每个元素为中轴，向两边找满足条件的最大的，每个元素为轴做一遍为O(n)，每个元素再往两边扩展，最多又是一个O(n)。
2. 动态规划：f(x,y)表示从x开始到y的子串为回文，则f(x,y)=f(x+1,y-1) && s[x] == s[y]。二维数组遍历O(n)。

### p6 实现一个将字符串进行指定行数变换的函数

找规律，按行遍历即可，2kn-2k+-p p表示列，k表示行 ，所以外层for循环为p递增，内层为p递增，在判断边界条件时候遇到些问题。最后的代码如下：

```c
char* convert(char* s, int numRows) {
    int n = numRows;
    int length = strlen(s);
    if (numRows == 1 || length < 1 || length <= numRows) {
        return s;
    }
    char *result = malloc(sizeof(char) * (length + 1));
    result[length] = '\0';
    int i = 0;
    int column = (length+(2*n-3)/(2*(n-1)));
//    n-1不会等于1了
    for (int p = 0; p < n ; p++) {
        for (int k = 0 ; k < column ; k++) {
            if (p == 0 || p == n-1) {
                if (2*k*n - 2*k - p >= 0 && 2*k*n - 2*k - p < length) {
                    result[i] = s[2*k*n - 2*k - p];
                    ++i;
//                    printf("%d个元素是原下标%d\n",i-1,2*k*n - 2*k - p);
                }
            } else {
                if (2*k*n - 2*k - p >= 0  && 2*k*n - 2*k - p < length) {
                    result[i] = s[2*k*n - 2*k - p];
                    ++i;
//                    printf("%d个元素是原下标%d\n",i-1,2*k*n - 2*k - p);
                }
                if (2*k*n - 2*k + p < length && 2*k*n - 2*k + p >= 0) {
                    result[i] = s[2*k*n - 2*k + p];
                    ++i;
//                    printf("%d个元素是原下标%d\n",i-1,2*k*n - 2*k + p);
                }
            }
            
        }
    }
    return result;
}
```

复杂度为O(1)

看了下答案：

```c++
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};
```

这个代码在c下可以么？。。感觉没改明白

## p7 反转整数

思路比较简单，就是模除10得到每位数，temp = temp * 10 + 模除得到的结果就可以。主要是判断是否越界。不能计算temp之后再判断，用最大最小值减去模除结果之后除10与当前temp比较。代码如下:

```c
int reverse(int x) {
    int max = (pow(2,30) - 1) * 2 + 1;
    int min = -1 * max - 1;
    int temp = 0;
    while (x != 0) {
        int addition = x % 10;
        if ((x<0 && temp < (min - addition) / 10) || (x >= 0 && temp > (max - addition) / 10)) {
            return 0;
        } else {
            temp = temp * 10 + addition;
        }
        x = x/10;
    }
    return temp;
}
```

## p8 实现 atoi，将字符串转为整数

按题目要求一步一步就可以：

1. 去头部空格
2. 判断正负数
3. 一位一位的读数字，非数字就结束

```c
int myAtoi(char* str) {
    int max = (pow(2,30) - 1) * 2 + 1;
    int min = -1 * max - 1;
    int temp = 0;
    //去空格
    while (str[0] == ' ') {
        str++;
    }
    if (str[0] == '\0') {
        return 0;
    }
    int mul = 1;
    //正负数
    if (str[0] == '-') {
        mul = -1;
        str++;
    } else if (str[0] == '+') {
        mul = 1;
        str++;
    } else if (str[0] < '0' || str[0] > '9') {
        return 0;
    }
    while(str[0] <= '9' && str[0] >= '0') {
        int addition = (str[0] - '0')*mul;
        if (temp < 0 && temp < (min - addition) / 10) {
            return min;
        } else if (temp > 0 && temp > (max - addition) / 10) {
            return max;
        } else {
            temp = temp * 10 + addition;
        }
        str++;
    }
    return temp;
}
```

## p9 判断一个整数是否是回文数

从题目描述中可以得到，负数一定不是回文数，0~9一定是回文数。

思路：

1.先计算出大于等于10的正整数的位数（负数或者小于10上面已经判断过）。

2.将该数字分为左右两部分

3.每次从左右两部分中去一位比较（左边取尾，右边去首）

```c
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    } else if (x < 10) {
        return true;
    }
    int length = 0;
    int temp = x;
    while (temp != 0) {
        length ++;
        temp /= 10;
    }
    temp = 1;
    for (int i = 0; i < length / 2; i++) {
        temp *= 10;
    }
    int left = 1;
    int right = 1;
    if (length % 2 == 0) {
        left = x / temp;
        right = x % temp;
    } else {
        left = x / (temp*10);
        right = x % temp;
    }
    bool result = true;
    while (left != 0) {
        int leftSingle = left % 10;
        left = left / 10;
        temp /= 10;
        int rightSingle = right / temp;
        right = right % temp;
        result = result && leftSingle == rightSingle;
    }
    return result;
}
```

## p10 正则表达式匹配

没想到什么简单的思路，就是按说明逐个去匹配的，具体看代码。

```c
bool isMatch(char* s, char* p) {
    //判断p中头部有没有星号
    if (strlen(p) == 0) {
        if (strlen(s) == 0) {
            return true;
        } else {
            return false;
        }
    } else if (strlen(p) == 1) {
        if (p[0] == '*') {
            return false;
        } else if (strlen(s) == 1) {
            if (p[0] == '.' || (p[0] == s[0])) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        //判断p[1]是否为*
        if (p[1] == '*') {
            bool curMatch = false;
            if (p[0] == '.') {
                for (int i = 1 ; i <= strlen(s); i++) {
                    curMatch = curMatch || isMatch(s+i, p+2);
                }
            } else {
                for (int i = 0 ; i < strlen(s) && s[i] == p[0]; i++) {
                    curMatch = curMatch || isMatch(s+i+1, p+2);
                }
            }
            return curMatch || isMatch(s, p+2);
        } else {
            if (p[0] == '.') {
                return strlen(s) != 0 && isMatch(s+1, p+1);
            } else {
                return strlen(s) != 0 && p[0] == s[0] && isMatch(s+1, p+1);
            }
        }
    }
    return false;
}
```

