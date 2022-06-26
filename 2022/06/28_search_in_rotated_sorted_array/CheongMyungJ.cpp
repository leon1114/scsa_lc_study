//Runtime: 3 ms, faster than 87.60% of C++ online submissions for Search in Rotated Sorted Array.
//Memory Usage: 11.1 MB, less than 74.69% of C++ online submissions for Search in Rotated Sorted Array.
//이진탐색 하는데, nums[start] > nums[end]인 경우 중 특이케이스에선 무조건 start를 올리거나 end를 내려아함. (16, 20번째줄)
//그게 아닌경우엔 일반적인 이진탐색 수행.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int median = 0;
        while(start < end){
            median = (start + end)/2;
            if (nums[median] == target)
                return median;
            if (nums[start] > nums[end]){
                if (target >= nums[start] && nums[median] <= nums[end]){
                    end = median - 1;
                    continue;
                }            
                else if (target <= nums[end] && nums[median] >= nums[start]){
                    start = median + 1;
                    continue;
                }    
            }
            if (nums[median] > target){
                end = median - 1;
            }
            else{
                start = median + 1;
            }
        }
        return nums[start] == target? start : -1;
    }
};
