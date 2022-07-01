#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize){
    int i;
    int check[50] = {0};
    int max = numsSize + 1;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] <= 0 || nums[i] > max) continue;
        check[nums[i]] = 1;
    }
    for (i = 1; i < numsSize + 1; i++) {
        if (check[i] == 0) return i;
    }
    return max;
}

int main(void) {
    printf("%d\n", firstMissingPositive((int[]){1,2,0}, 3)); // 3
    printf("%d\n", firstMissingPositive((int[]){3,4,-1,1}, 4)); // 2
    return 0;
}