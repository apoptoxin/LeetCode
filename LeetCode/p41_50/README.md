## p41 缺失的第一个正数
**核心思路就是把值为v的元素放到v-1的位置（v=nums[i]），这样，再次遍历数据，i与num[i]不相等的就是我们要找的了.**

记录一下解题中的错误想法：从头开始遍历，记录最小值及与最小值连续的最大值，然后再从尾开始遍历，这样问题是如果中间连续的是一段一段的，比如，5~8，然后有2~3，这样当前记录的就是5~8，如果下一个是4，就只能记录到4~8，前面2~3也连不上了。从尾遍历的时候先遍历到2~4这段，然后读到8，也会断掉，思路从开始就是错误的。

```c
int firstMissingPositive(int* nums, int numsSize) {
    //核心思路就是把值为v的元素放到v-1的位置（v=nums[i]），这样，再次遍历数据，i与num[i]不相等的就是我们要找的了
    for (int i = 0; i < numsSize; ) {
        if (nums[i] > 0 && i != nums[i] - 1 && nums[i] - 1 < numsSize && nums[i] - 1 != nums[nums[i] - 1] - 1) {
            swapTwoInts(nums+i, nums+nums[i]-1);
        } else {
            i++;
        }
    }
    for (int i = 0 ; i < numsSize ; i++) {
        if (nums[i] - 1 != i) {
            return i+1;
        }
    }
    return numsSize < 1 ? 1 : nums[numsSize-1] + 1;
}
```


## p42 接雨水
第一步：从左向右遍历，遇到比当前轴高的就计算高度并更新当前轴位置，否则就继续算下一个位置
第二步：从右向左遍历，遇到比当前轴高或相等的就计算高度并更新当前轴位置，否则就继续算下一个位置

```c
int trap(int* height, int heightSize) {
    int area = 0;
    int count = 0;
    int last = 0;
    for (int i = 0 ; i < heightSize ; i++) {
        if (height[i] <= height[last]) {
            count += height[i];
        } else {
            area += (height[last] * (i - last) - count);
            last = i;
            count = height[i];
        }
    }
    last = heightSize - 1;
    count = 0;
    for (int i = heightSize - 1 ; i >= 0 ; i--) {
        if (height[i] < height[last]) {
            count += height[i];
        } else {
            area += (height[last] * (last - i) - count);
            last = i;
            count = height[i];
        }
    }
    return area;
}
```

## p43 字符串相乘
思路就是一位一位的乘然后加上进位，累加，就模拟计算乘法的过程就行了

## p44 通配符匹配
思路1：
动态规划


1. p[j] == '\*' table[i][j] = table[i-1][j-1] || /\*匹配多个\*/table[i][j-1] || /\*匹配0个\*/table[i-1][j];
2. p[j] == '?' table[i][j] = table[i-1][j-1];
3. else table[i][j] = table[i-1][j-1] && s[i]==p[j]

思路2：
网上找来的，假设我们用两个指针分别指向s和p字符串中要匹配的位置，首先分析下通配符匹配过程中会有哪些情况是成功：
1. s的字符和p的字符相等
2. p中的字符是?，这时无论s的字符是什么都可以匹配一个
3. p中遇到了一个\*，这时无论s的字符是什么都没关系
4. 之前的都不符合，但是p在之前的位置有一个\*，我们可以从上一个\*后面开始匹配
5. s已经匹配完，但是p后面还有很多连续的\*

这里1和2的情况比较好处理，关键在于如何处理3和4的情况。当我们遇到一个\*时，因为之后可能要退回至该位置重新匹配，我们要将它的下标记录下来，比如idxstar。但是，当我们连续遇到两次4的情况，如何保证我还是能继续匹配s，而不是每次都退回idxstar+1导致循环呢？所以我们还要记录一个idxmatch，用来记录用上一个\*连续匹配到的s中的下标。最后，对于情况5，我们用一个循环跳过末尾的*跳过就行了。

网上说这种算法的时间复杂度是O(n)，空间复杂度是O(1)。空间复杂度好理解，时间复杂度再看下。

下面贴一下java的代码，c代码也可以按照这个写，写法差距不大，就不重新写了
```c
public class Solution {
    public boolean isMatch(String s, String p) {
        int idxs = 0, idxp = 0, idxstar = -1, idxmatch = 0;
        while(idxs < s.length()){
            // 当两个指针指向完全相同的字符时，或者p中遇到的是?时
            if(idxp < p.length() && (s.charAt(idxs) == p.charAt(idxp) || p.charAt(idxp) == '?')){
                idxp++;
                idxs++;
            // 如果字符不同也没有?，但在p中遇到是*时，我们记录下*的位置，但不改变s的指针
            } else if(idxp < p.length() && p.charAt(idxp)=='*'){
                idxstar = idxp;
                idxp++;
                //遇到*后，我们用idxmatch来记录*匹配到的s字符串的位置，和不用*匹配到的s字符串位置相区分
                idxmatch = idxs;
            // 如果字符不同也没有?，p指向的也不是*，但之前已经遇到*的话，我们可以从idxmatch继续匹配任意字符
            } else if(idxstar != -1){
                // 用上一个*来匹配，那我们p的指针也应该退回至上一个*的后面
                idxp = idxstar + 1;
                // 用*匹配到的位置递增
                idxmatch++;
                // s的指针退回至用*匹配到位置
                idxs = idxmatch;
            } else {
                return false;
            }
        }
        // 因为1个*能匹配无限序列，如果p末尾有多个*，我们都要跳过
        while(idxp < p.length() && p.charAt(idxp) == '*'){
            idxp++;
        }
        // 如果p匹配完了，说明匹配成功
        return idxp == p.length();
    }
}
```

## p45 跳跃游戏II
我们要探索所有的可能性，这里用快慢指针分出一块当前结点能跳的一块区域，然后再对这块区域遍历，找出这块区域能跳到的下一块区域的上下边界，每块区域都对应一步，直到上界超过终点时为之。
```c
int jump(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }
    int *step = calloc(numsSize,sizeof(int));
    for (int i = 0 ; i < numsSize; i++) {
        for (int j = i+1; j - i <= nums[i] && j < numsSize ; j++) {
            int cur = step[i] + 1;
            if (step[j] == 0 || step[j] > cur) {
                step[j] = cur;
            }
        }
    }
    return step[numsSize-1];
}
```

## p46 全排列
思路就是递归，每次交换一位，然后递归交换后面的
具体见代码
```c
void constructSingle(int* nums, int numsSize, int** result, int *posToSave, int axis) {
    if (axis >= numsSize - 1) {
        int *tmp = malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            tmp[i] = nums[i];
//            printf("%d ",tmp[i]);
        }
//        printf("\n------------------\n");
        result[*posToSave] = tmp;
        *posToSave = (*posToSave)+1;
    }
    //axis及之前的都固定，交换后面的
    for (int i = axis + 1; i < numsSize ; i++) {
        //交换axis+1和i
        int tmp = nums[axis+1];
        nums[axis+1] = nums[i];
        nums[i] = tmp;
        //继续
        constructSingle(nums, numsSize, result, posToSave, axis+1);
        //换回来
        nums[i] = nums[axis+1];
        nums[axis+1] = tmp;
        
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {
    int count = 1;
    for (int i = 1 ; i <= numsSize; i++) {
        count = count * i;
    }
    if (returnSize) {
        *returnSize = count;
    }
    int ** re = malloc(sizeof(int *) *count);
    int pos = 0;
    constructSingle(nums, numsSize, re, &pos, -1);
    return re;
}

```

## p47 全排列II
解题思路和上一题类似，也是深度优先遍历搜索（DFS）.
首先对所以的数字进行一次排序，然后从头开始，深度优先遍历，如果遇到重复的就跳过。
具体实现可以看下代码

## p48 旋转图像
要把n*n矩阵顺时针旋转90度，需要进行以下2个步骤：

1. 横向交换,每行第i个和倒数第i个交换(相当于以纵向中间为轴翻转）
2. 对角线交换，以左下到右上为轴j进行旋转

```c
void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    //step 1 横向交换，每行第i和和倒数第i个交换
    for (int i = 0 ; i < matrixRowSize ; i++) {
        for (int j = 0 ; j < matrixRowSize && j < matrixRowSize - 1 - j; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixRowSize-1-j];
            matrix[i][matrixRowSize-1-j] = tmp;
        }
    }
    //step 2 对角线交换，以左下到右上为轴交换
    for (int i = 0 ; i < matrixRowSize; i++) {
        for (int j = 0 ; j < matrixRowSize && i + j < matrixRowSize-1; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixRowSize-1-j][matrixRowSize-1-i];
            matrix[matrixRowSize-1-j][matrixRowSize-1-i] = tmp;
        }
    }
}

```

## p49 字母异位词分组
解题思路就是分别统计每个单词中每个字母出现的次数，以这个作为key（由于这个次数不好作为key来存储，可以转化成，将对应的字母按顺序及出现次数排序构造出字符串作为key）。value就是对应的字符串在数组中位置所组成的数组了。
统计之后直接输出结果即可

## p50 pow(x,n)
二分，注意n是正负数以及奇数偶数，还有注意越界
```c
double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    } else if (n == 1) {
        return x;
    } else if (n == -1) {
        return 1.0/x;
    }
    double half = myPow(x, n/2);
    if (n % 2 != 0) {
        return half * half * ((n < 0) ? 1.0/x : x);
    } else {
        return half * half;
    }
}
```