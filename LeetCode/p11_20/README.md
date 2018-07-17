## p11 盛水最多的容器

从左右两边向中间收缩，每次把高度较小的边向高度较大的边移动即可，遍历一次，时间复杂度为O(n)。

原理我尽量解释：面积=宽*高，初始状态的宽度为最大的，所以，高度增加才对结果有帮助，所以需要小边向大边移动，否则，高度还是小边的高度没变化，对计算结果没有影响。

## p12 整数转罗马数字

没什么好说的，就是从大到小判断吧，一位一位（或者两位，也就是六种特例情况）输出就好了。

## p13 罗马数字转整数

和p12相反，从头到尾，每次先读两位判断是否是合法罗马数。如果不是的话就读1位判断出数字。以此类推直到读完整个字符串。

## p14 查找字符串数组中的最长公共前缀 

思路比较简单，首先，以第一个字符串作为最长的公共前缀，然后顺序用后续的字符串和这个公共前缀比较，然后更新这个前缀。比较完成后就得出结果了。

## p15 三数之和

我自己的思路：先排序，O(nlogn)。然后从头开始，固定一个位置，找另两个数，每次查找都重固定位置后一个到结尾这段找两个数，查找复杂度为O(n)。然后向后移动这个固定位置，最多移动O(n)次，所以整体时间复杂度为O(n2)。

**动态增加指针指向内存大小可以用realloc函数，学到了~** ~~像我自己写的那种方式简直是傻。~~

## p16 最接近的三数之和

和第15题三数之和思路一样，只不过，和0比较变成了和target比较，而且，不需要去重了，每次计算之后更新当前最接近的值就可以。

## p17 电话号码的字母组合

递归+hashmap。hashmap仅作为加速用，我这里没写，我的写法就是纯遍历。

## p18 四数之和

现在如果推导到K-Sum问题，那么按照这个套路（虽然不一定最优，但是很容易想到也很好啊），做法是：  

1. 排序
2. 前K-2个数使用循环遍历组合  
3. 最后两个数，在2选择剩余的区间内，设立p q指针，指向首尾，此时如果K个位置的和小于目标值，p++（注意条件4），大于的话 q–，等于的话输出。知道p>=q位置  
4. 在改变前K-1个的指针时，如果移动后和移动前的值一样，那么要继续移动，直到不一样。。即前K-1个再做++等运算时都必须考虑到4这个条件。

```c
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    quickSort(nums, numsSize);
    int total = 0;
    int** result = NULL;
    for (int k = 0 ; k < numsSize - 3 ; k++) {
        if(k>0 && nums[k]==nums[k-1])continue;
        for (int i = k+1 ; i < numsSize - 2; i++) {
            if(i>k+1 && nums[i]==nums[i-1])continue;
            //固定最小元素位置，在后面找两个元素和为-nums[i]的
            for (int j = i+1, end = numsSize-1 ; j < end ;) {
                //以i, j, end 这3个元素判断是否满足条件；
                int cal = nums[k] + nums[i] + nums[j] + nums[end];
                if (cal == target) {
                    
                    int* curPtr = (int*)malloc(sizeof(int) * 4);
                    curPtr[0] = nums[k];
                    curPtr[1] = nums[i];
                    curPtr[2] = nums[j];
                    curPtr[3] = nums[end];
                    if (total == 0) {
                        result = (int**)malloc(sizeof(int*));
                    } else {
                        result = (int**)realloc(result,(total+1)*sizeof(int*));
                    }
                    result[total] = curPtr;
                    total++;
                    do{++j;} while (end > j && nums[j] == nums[j-1]);
                } else if (cal > target) {
                    do{--end;} while (end > j && nums[end+1] == nums[end]);
                } else {
                    do{j++;} while (end > j && nums[j] == nums[j-1]);
                }
            }
        }
    }
    *returnSize = total;
    return result;
}
```

## p19 删除链表的倒数第N个节点 

遍历一遍就可以，思路没什么好说的，直接上代码就能看懂了

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //当前指针
    struct ListNode *cur = head;
    //当前指针前面n个指针
    struct ListNode *cur_n = head;
    //当前指针前面n+1个指针
    struct ListNode *cur_np1 = head;
    int step = 0;
    while (cur != NULL) {
        if (step >= n-1) {
            //保持不动
            cur_np1 = cur_n;
        }
        if (step >= n) {
            cur_n = cur_n->next;
        }
        cur = cur->next;
        step++;
    }
    //需要去掉的是cur_n
    if (cur_n == head && cur_n != NULL) {
        head = head->next;
    } else if (cur_np1 != NULL && cur_n != NULL) {
        cur_np1->next = cur_n->next;
    }
    return head;
}
```

