//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
//Memory Usage: 8.2 MB, less than 70.19% of C++ online submissions for Sort Colors.
//0, 1, 2 숫자갯수 구해서 그대로 넣어줌. 근데 0은 걍 첨부터 넣어줘도됨

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num_cnt[3] = {0,};
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                nums[num_cnt[0]++] = 0;
            }
            else{
                num_cnt[nums[i]]++;
            }
        }
        for (int i = num_cnt[0]; i < num_cnt[0] + num_cnt[1]; i++){
            nums[i] = 1;
        }
        for (int i = num_cnt[0] + num_cnt[1]; i < nums.size(); i++){
            nums[i] = 2;
        }
    }
};
