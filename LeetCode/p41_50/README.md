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
思路就是一位一位的乘，累加，就模拟计算乘法的过程就行了

## p44 通配符匹配
