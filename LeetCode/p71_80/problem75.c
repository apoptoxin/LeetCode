//
//  problem75.c
//  LeetCode
//
//  Created by liunan on 2019/6/2.
//  Copyright © 2019 micronil.com. All rights reserved.
//

#include "problem75.h"

void sortColors(int* nums, int numsSize){
    //一趟排序，用r、w、b表示当前的下标，每次向后读一个数，更新值和rwb的下标
    int red = -1;
    int white = -1;
    int blue = -1;
    for (int i = 0 ; i < numsSize; i++) {
        if (nums[i] == 2) {
            nums[++blue] = 2;
        } else if (nums[i] == 1) {
            //如果是white
            nums[++white] = 1;
            ++blue;
            if (white < blue) {
                //表示之前有blue;
                nums[blue] = 2;
            }
        } else {
            nums[++red] = 0;
            ++white;
            ++blue;
            if (red < white) {
                //之前有white
                nums[white] = 1;
                if (white < blue) {
                    //还有blue
                    nums[blue] = 2;
                }
            } else if (red < blue) {
                //之前只有blue没有white
                nums[blue] = 2;
            }
        }
    }
}
