// Runtime: 5 ms, faster than 39.09% of C online submissions for Sort Colors.
// Memory Usage: 6 MB, less than 39.09% of C online submissions for Sort Colors.
// O(n) 츄라이
// O(n) 맞나.?
void sortColors(int* nums, int numsSize){
    int red = 0, blu = numsSize - 1, whi = 0;
    while(whi <= blu) {
        // printf("%d %d %d\n", red, whi, blu);
        while(red < numsSize - 1 && nums[red] == 0) red++;
        while(blu > 0 && nums[blu] == 2) blu--;
        if (red > whi) { whi = red; continue; }
        if (nums[whi] == 1) { whi++; continue; }
        else if (nums[whi] == 0) {
            nums[whi] = nums[red];
            nums[red++] = 0;
        } else if (nums[whi] == 2) {
            nums[whi] = nums[blu];
            nums[blu--] = 2;
        }
    }
}


// // Runtime: 5 ms, faster than 39.09% of C online submissions for Sort Colors.
// // Memory Usage: 6.1 MB, less than 22.87% of C online submissions for Sort Colors.
// void sortColors(int* nums, int numsSize){
//     // 일단 O(2n)
//     int col_cnts[3] = {0, }, cnt = 0;
//     for(int i = 0; i < numsSize; i++) {
//         col_cnts[nums[i]]++;
//     }
//     for(int i = 0; i < 3; i++) {
//         while(col_cnts[i]-- > 0){
//             nums[cnt++] = i;
//         }
//     }
// }
