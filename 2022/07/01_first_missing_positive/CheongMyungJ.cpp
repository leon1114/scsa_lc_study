//Runtime: 200 ms, faster than 74.46% of C++ online submissions for First Missing Positive.
//Memory Usage: 83.5 MB, less than 26.17% of C++ online submissions for First Missing Positive.\
//기본적으로 답은 배열의 항목 갯수보다 클 수가 없음. 
//우선 답을 length + 1로 설정한다음, 0 이하이면 하나씩 줄이고, 답보다 큰 수가 나와도 하나씩 줄임.
//답보다 작은 숫자가 나오면 체크배열에 체크해놓음
//한바퀴 다 돌고 난 뒤 체크배열을 보고 최종 답을 찾아냄.
//이론상 max 2*N 이므로 O(N) 만족

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool check_arr[500001] = {0,};
        int len = nums.size();
        int ret = len + 1;
        for (int i = 0; i < len; i++){
            if (nums[i] <= 0)
                ret--;
            else if (nums[i] >= ret)
                ret--;
            else
                check_arr[nums[i]-1] = true;
        }
        for (int i = 0; i < ret; i++){
            if (check_arr[i] == false)
                return i + 1;
        }
        
        return ret;
    }
};
