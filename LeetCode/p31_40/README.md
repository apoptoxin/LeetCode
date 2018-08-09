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



