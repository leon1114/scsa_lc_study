//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
//Memory Usage: 6.9 MB, less than 95.97% of C++ online submissions for Subsets.
//간단하게 재귀로. 넣은거 한번 안넣은거 한번 해서 쭉 들어간다.
//레퍼런스 잘 이용하면(vt) 복사가 적게 일어나니까 괜찮은듯
class Solution {
public:
    void recursive(vector<int>& nums, vector<int>& vt, int depth, vector<vector<int>>& ret){
        if (depth == nums.size()){
            ret.push_back(vt);
            return;
        }
        
        vt.push_back(nums[depth]);
        recursive(nums, vt, depth+1, ret);
        vt.pop_back();
        recursive(nums, vt, depth+1, ret);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        recursive(nums, temp, 0, ret);
        return ret;
    }
};
