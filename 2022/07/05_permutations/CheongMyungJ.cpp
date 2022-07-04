//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutations.
//Memory Usage: 8.3 MB, less than 14.80% of C++ online submissions for Permutations.
//재귀로 풀면 간단하네. vector size만큼 depth 들어가서 vector<vector<int>>에 push한다.
//그런데 같은 인덱스는 중복 불가이므로 체크배열 하나 만들어서 해당 인덱스가 이미 포함되었는지 여부를 판단해야함(check_arr)

class Solution {
public:
    void recursive(vector<vector<int>>& ret, vector<int>& nums, vector<int> sub_nums, bool* check_arr, int depth){
        if (depth == 0){
            ret.push_back(sub_nums);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (check_arr[i] == true)
                continue;
            sub_nums.push_back(nums[i]);
            check_arr[i] = true;
            recursive(ret, nums, sub_nums, check_arr, depth - 1);
            sub_nums.pop_back();
            check_arr[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> sub_nums;
        bool check_arr[6];
        for (int i = 0; i < 6; i++)
            check_arr[i] = false;
        recursive(ret, nums, sub_nums, check_arr, nums.size());
        return ret;
    }
};
