// c로 구현할 시간이 없어서 오늘은 cpp...
// Runtime: 3 ms, faster than 73.21% of C++ online submissions for Subsets.
// Memory Usage: 14.9 MB, less than 33.37% of C++ online submissions for Subsets.

class Solution {
public:
    vector<vector<int>> ret;
    
    void dfs(vector<int>& nums, int depth, vector<int>& el) {
        if (depth == nums.size()) {
            ret.push_back(el);
            return;
        }
        vector<int> elp = el;
        // do nothing
        dfs(nums, depth + 1, elp);
        // add num
        el.push_back(nums[depth]);
        dfs(nums, depth + 1, el);
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(nums, 0, v);
        return ret;
    }
};
