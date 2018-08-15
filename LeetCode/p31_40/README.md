## p31 下一个排列

1. 从前往后找到最后一个升序
2. 找到了升序，index 和 index-1。从index开始到numsSize-1中找比nums[index-1]大的数中的最小值
3. 将找到的最小值和nums[index-1]交换
4. 后面部分排序

```c
void nextPermutation(int* nums, int numsSize) {
    if (numsSize < 2) {
        return;
    }
    int index = -1;
    //从前往后找到最后一个升序
    for (int i = 1 ; i < numsSize ; i++) {
        if (nums[i] > nums[i-1]) {
            index = i;
        }
    }
    if (index > 0) {
        //找到了升序，index 和 index-1。从index开始到numsSize-1中找比nums[index-1]大的数中的最小值
        int tmpIndex = index;
        for (int i = index; i<numsSize; i++) {
            if (nums[i] > nums[index-1] && nums[i] < nums[tmpIndex]) {
                tmpIndex = i;
            }
        }
        int temp = nums[index-1];
        nums[index-1] = nums[tmpIndex];
        nums[tmpIndex] = temp;
        //index到结尾 sort
        quickSort(nums+index, numsSize - index);
    } else {
        //全排列，逆序就可以
        quickSort(nums, numsSize);
    }
}
```

## p32 最长有效括号
用a来记录从第i个元素开始最长的有效括号长度，那么a[i]就等于：

1. 如果s[i]为')'，则a[i]=0
2. 计算a[i+2]开始最长+s[i]和s[i+1]，得到长度l1，然后累加上a[i+l1]得到l1;
3. 计算a[i+1]开始最长，为l2,加上s[i]和s[i+l2],结果存在l2,然后累加上a[i+l2]得到l2;
4. a[i] = l1和l2中的大者

从后向前遍历

```c
int longestValidParentheses(char* s) {
    int length = strlen(s);
    int total = 0;
    int *a = malloc(sizeof(int) * length);
    for (int i = length-1; i >= 0; i--) {
        if (i < length -1 && s[i] == '(') {
            int l1 = 0;
            if (s[i+1] == ')') {
                l1 = 2;
                if (i+l1 < length) {
                    l1 = a[i+l1] + l1;
                }
            }
            int l2 = 0;
            if (i+1+a[i+1] < length && s[i+1+a[i+1]] == ')') {
                l2 = a[i+1] + 2;
                if (i+l2 < length) {
                    l2 = a[i+l2]+l2;
                }
            }
            a[i] = l1>l2?l1:l2;
            total = total > a[i] ?total:a[i];
        } else {
            a[i] = 0;
        }
    }
    return total;
}
```

## p33 搜索旋转排序数组
二分查找，只是判断查找范围时和普通二分查找不同
直接贴代码

```c
int searchFromNums(int* nums, int start, int end, int target) {
    if (start >= end) {
        if (start > end) {
            return -1;
        } else {
            return nums[start] == target ? start : -1;
        }
    }
    //这里start最多等于mid,mid一定小于end
    int mid = ( start + end ) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if(start == mid) {
        return searchFromNums(nums, mid+1, end, target);
    } else {
        if (nums[mid] > nums[start]) {
            //旋转点在mid~end
            if (nums[mid] < target) {
                return searchFromNums(nums, mid+1, end, target);
            } else {
                int pos = searchFromNums(nums, start, mid-1, target);
                if (pos >= 0) {
                    return pos;
                } else {
                    return searchFromNums(nums, mid+1, end, target);
                }
            }
        } else {
            //旋转点在start ~ mid
            if (nums[mid] > target) {
                return searchFromNums(nums, start, mid-1, target);
            } else {
                int pos = searchFromNums(nums, start, mid-1, target);
                if (pos >= 0) {
                    return pos;
                } else {
                    return searchFromNums(nums, mid+1, end, target);
                }
            }
        }
    }
    return -1;
}
```

## p34 在排序数组中查找元素的第一个和最后一个位置

二分查找的变形，多几次递归继续查找而已

```c
int indexForTarget(int* nums, int start, int end, int target, bool left) {
    //left这个bool型表示的是向左找到底，false就是向右找到底
    if (start >= end) {
        return (start == end && nums[start] == target) ? start : -1;
    }
    int index = -1;
    int mid = (start + end) / 2;
    if (nums[mid] == target) {
        index = mid;
    }
    if (mid == start && nums[mid] == target) {
        if (left) {
            return index;
        } else {
            return nums[end] == target ? end : index;
        }
    } else {
        if ((left && nums[mid] == target) || nums[mid] > target) {
            int find = indexForTarget(nums, start, mid-1, target, left);
            return find >= 0 ? find : index;
        } else {
            int find = indexForTarget(nums, mid+1, end, target, left);
            return find >= 0 ? find : index;
        }
    }
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *re = malloc(sizeof(int) * 2);
    if (returnSize) {
        *returnSize = 2;
    }
    re[0] = indexForTarget(nums, 0, numsSize-1, target, true);
    re[1] = indexForTarget(nums, 0, numsSize-1, target, false);
    return re;
}
```

## p35 搜索插入位置
二分查找

```c
int searchInsertPosition(int *nums, int start, int end, int target) {
    if (start > end) {
        if (end >= 0 && nums[end] > target) {
            return end;
        } else {
            return start;
        }
    }
    int mid = (start + end) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] < target) {
        return searchInsertPosition(nums, mid+1, end, target);
    } else {
        return searchInsertPosition(nums, start, mid-1, target);
    }
}
```

## p36 有效的数独
使用O(n)的额外空间，用位运算，假设第i行有5 那么 col[i] = col[i] | 1<<5;
```c
int col[9] = {0}; //表示第i行的值
int row[9] = {0}; //表示第i列的值
int rec[9] = {0}; //rec表示3*3的方格，下标=行下标/3*3+列下标/3
```

依次遍历每个点，即可得到结果

```c
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    //用位运算，假设第i行有5 那么 col[i] = col[i] | 1<<5;
    int col[9] = {0}; //表示第i行的值
    int row[9] = {0}; //表示第i列的值
    int rec[9] = {0}; //rec表示3*3的方格，下标=行下标/3*3+列下标/3
    for (int i = 0 ; i < 9 && i < boardRowSize; i++) {
        for (int j = 0 ; j < 9 && j < boardColSize; j++) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            }
            int t = 1 << (c-'0');
            int ri = (i/3)*3+(j/3);
            if ((row[i] & t) > 0) {
                return false;
            } else if ((col[j] & t) > 0) {
                return false;
            } else if ((rec[ri] & t) > 0) {
                return false;
            }
            row[i] |= t;
            col[j] |= t;
            rec[ri] |= t;
        }
    }
    return true;
}
```

## p37 解数独
深度优先遍历，每次取个数填，看是否满足
第36题的改进版

## p38 报数
报数序列是指一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。

这个题主要就是理解题意，看前5个数可能看不出规律，那么再多看一下
```
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221 
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
10.     13211311123113112211
```

这样就比较明显了，后一个数是前一个数中，重头爱是统计个数，比如第5个是111221，那么第6个就是：3个1，2个2，1个1。所以第六个数为312211.
看懂题之后就好解决了，遍历就可以得到结果。
下面是网上看到的一个解答，思路一样，只是细节可能稍微好些，执行时间短：
```c
char* countAndSay(int n) {
    char *num = (char*)malloc(sizeof(char)*2);
    char *num1, *p, *q;
    int index;
    // char c;
    
    num[0] = '1';
    num[1] = '\0';
    while(n>1){
        index = 0;
        p = q = num;
        num1 = (char*)malloc(sizeof(char)*strlen(num)*2+1);
        
        while(*q){
            if(*p != (*(q + 1))){
                num1[index++] = q - p + '1';
                num1[index++] = *p;
                p = q + 1;
            }
            q++;
        }
        num1[index] = '\0';
        
        free(num);
        num = num1;
        
        n--;
    }
    
    return num;
}
```

## p39 组合总和
排序+深度优先遍历，直接上代码:
```c
int cmpfunc39 (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int total = 0;
    int **result = malloc(sizeof(int*));
    int *columnSize = malloc(sizeof(int));
    int columnSizeCount = 0;
    int *tmp = malloc(sizeof(int) * target);//用于记录暂存的数值下标
    int pos = -1;
    qsort(candidates, candidatesSize, sizeof(int), cmpfunc39);
    int axis = 0;
    int curTarget = target;
    while (pos >= 0 || axis < candidatesSize) {
        ////////////////
        printf("tmp:");
        for (int i = 0 ; i <= pos ; i++) {
            printf("%d ",candidates[tmp[i]]);
        }
        printf("\r\npos:%d curAxisVal:%d curTar:%d\n\r",pos,candidates[axis],curTarget);
        ////////////////
        if (curTarget <= 0) {
            if (curTarget == 0) {
                int *out = malloc(sizeof(int) * (pos+1));
                for (int i = 0 ; i <= pos; i++) {
                    out[i] = candidates[tmp[i]];
                }
                if (total == 0) {
                    result = malloc(sizeof(int *));
                    
                    result[0] = out;
                } else {
                    result = realloc(result,sizeof(int*)*(total+1));
                    result[total] = out;
                }
                if (columnSizeCount == 0) {
                    columnSize = malloc(sizeof(int));
                } else {
                    columnSize = realloc(columnSize, sizeof(int) * (columnSizeCount+1));
                }
                columnSize[columnSizeCount] = pos + 1;
                columnSizeCount++;
                total++;
            }
            //回滚最后一位
            curTarget += candidates[tmp[pos]];
            axis = tmp[pos] + 1;
            pos--;
            while (axis >= candidatesSize && pos >= 0) {
                curTarget += candidates[tmp[pos]];
                axis = tmp[pos] + 1;
                pos--;
            }
        } else {
            tmp[++pos] = axis;
            curTarget -= candidates[axis];
        }
    }
    if (returnSize) {
        *returnSize = total;
    }
    if (columnSizes) {
        *columnSizes = columnSize;
    }
    return result;
}
```

