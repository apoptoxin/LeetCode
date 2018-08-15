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

