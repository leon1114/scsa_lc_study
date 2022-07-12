// D&C

int max(int a, int b) {return a>b?a:b;}
int is_pos(int i) {return i>=0?1:0;}

int dnc(int* nums, int left, int right) {
    int mid = (right + left) / 2;
    int mid_val = nums[mid];
    if (mid_val < 0) return mid_val;
    int prev_sign = is_pos(nums[0]), this_sign;
    while(left < right) {
        
    }
}
int max(int a, int b) {return a>b?a:b;}
int is_pos(int i) {return i>=0?1:0;}

int dnc(int* nums, int left, int right) {
    int mid = (right + left) / 2;
    int mid_val = nums[mid];
    if (mid_val < 0) return mid_val;
    int prev_sign = is_pos(nums[0]), this_sign;
    while(left < right) {
        
    }
}

int maxSubArray(int* nums, int numsSize){
    return dnc(nums, 0, numsSize - 1);
}

// // O(n) solution
// // 4 cases
// // 1: pos-> pos: sub 올리고
// // 2: pos-> neg: max랑 sub 비교 
// // 3: neg-> pos: sub < 0 => sub 초기화 else 뒤에꺼랑 붙여서 진행
// // 4: neg-> neg: max랑 단일 비교
// // Runtime: 229 ms, faster than 10.46% of C online submissions for Maximum Subarray.
// // Memory Usage: 12.5 MB, less than 10.56% of C online submissions for Maximum Subarray.
// int is_pos(int i) {return i>=0?1:0;}

// int maxSubArray(int* nums, int numsSize){
//     int cum_sum = nums[0], max_sum = nums[0];
//     int prev_sign = is_pos(nums[0]), this_sign;
//     for (int i = 1; i < numsSize; i++) {
//         this_sign = is_pos(nums[i]);
//         if (max_sum < nums[i]) max_sum = nums[i];
//         if (this_sign && !prev_sign && cum_sum < 0) cum_sum = nums[i];
//         else cum_sum += nums[i];
//         if (max_sum < cum_sum) {
//             max_sum = cum_sum;
//         }
//         prev_sign = this_sign;
//     }
//     return max_sum;


int maxSubArray(int* nums, int numsSize){
    return dnc(nums, 0, numsSize - 1);
}

// // O(n) solution
// // 4 cases
// // 1: pos-> pos: sub 올리고
// // 2: pos-> neg: max랑 sub 비교 
// // 3: neg-> pos: sub < 0 => sub 초기화 else 뒤에꺼랑 붙여서 진행
// // 4: neg-> neg: max랑 단일 비교
// // Runtime: 229 ms, faster than 10.46% of C online submissions for Maximum Subarray.
// // Memory Usage: 12.5 MB, less than 10.56% of C online submissions for Maximum Subarray.
// int is_pos(int i) {return i>=0?1:0;}

// int maxSubArray(int* nums, int numsSize){
//     int cum_sum = nums[0], max_sum = nums[0];
//     int prev_sign = is_pos(nums[0]), this_sign;
//     for (int i = 1; i < numsSize; i++) {
//         this_sign = is_pos(nums[i]);
//         if (max_sum < nums[i]) max_sum = nums[i];
//         if (this_sign && !prev_sign && cum_sum < 0) cum_sum = nums[i];
//         else cum_sum += nums[i];
//         if (max_sum < cum_sum) {
//             max_sum = cum_sum;
//         }
//         prev_sign = this_sign;
//     }
//     return max_sum;
