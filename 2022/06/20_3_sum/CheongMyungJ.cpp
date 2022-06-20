//Runtime: 121 ms, faster than 62.21% of C++ online submissions for 3Sum.
//Memory Usage: 24.5 MB, less than 20.54% of C++ online submissions for 3Sum.
//2개 먼저 고르고 나머지 하나는 두개의 합 * -1인 숫자이니 결국 O(n^2)인 풀이로 해결할 수 있다.
//가지치기를 할 수 있도록 정렬 한번 때려준담에 앞에 2개 숫자 고르고 마지막 하나는 2개숫자보다 큰 숫자로 제한한다면 수행시간도 절반으로 줄고 중복도 자연스럽게 막아진다.
//마지막으로 나머지 한개 숫자를 고르는건 20만개짜리 배열을 이용해서 O(1)로 찾으면 좋다. (unordered_map : hash 로 해봤는데 수행시간 큰 차이 없고 메모리를 오히려 많이쓰더라...)
//중복 제거를 위해 2개 숫자 고를때 앞 숫자랑 동일하면 건너뛰는것도 추가해야함.

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int look_up_table[200010] = { 0, };
        
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            look_up_table[nums[i] + 100000]++;
        }

        sort(nums.begin(), nums.end());

        int i_before, j_before;
        for (int i = 0; i < len - 1; i++) {
            if (i != 0 && i_before == nums[i]) continue;
            i_before = nums[i];
            for (int j = i + 1; j < len; j++) {
                if (j != 1 && j_before == nums[j]) continue;
                j_before = nums[j];
                int sum2 = (0 - nums[i] - nums[j]);
                if (sum2 < 0 || sum2 < nums[j]) break;
                if (sum2 > 100000 || sum2 < -100000) continue;
                int same_cnt = (sum2 == nums[i]) ? 1 : 0;
                same_cnt += (sum2 == nums[j]) ? 1 : 0;
                if (look_up_table[sum2 + 100000] > same_cnt) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(sum2);
                    ret.push_back(temp);
                }
            }
        }
        return ret;
    }
};
