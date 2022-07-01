#include <stdio.h>

// Runtime: 174 ms, faster than 64.03% of C online submissions for First Missing Positive.
// Memory Usage: 30 MB, less than 73.74% of C online submissions for First Missing Positive.

// 배열이 있을 때 가장 큰 가능한 값은 numsSize + 1 (숫자가 빠진거없이 다 차있을때)
// 그래서 500000개 짜리 hash table에 체크하고 
// 1부터 올라가면서 체크 안됐으면 바로 return

// commit 안돼서 다시 함

int firstMissingPositive(int* nums, int numsSize){
    int i;
    int check[500000 + 10] = {0};
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