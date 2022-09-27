// Runtime: 354 ms, faster than 17.18% of C++ online submissions for Find the Duplicate Number.
// Memory Usage: 61.2 MB, less than 91.49% of C++ online submissions for Find the Duplicate Number.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), i = 0, res;
        while(i < n) {
            if(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else 
                i++;
        }
        for(int j = 0; j < n; j++) {
            if(nums[j] != j+1) {
                res = nums[j];
                break;
            }
        }
        return res;
    }
};
