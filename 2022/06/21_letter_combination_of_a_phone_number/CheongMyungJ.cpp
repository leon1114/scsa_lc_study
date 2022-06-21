//Runtime: 310 ms, faster than 10.75% of C++ online submissions for 3Sum Closest.
//Memory Usage: 25.8 MB, less than 6.15% of C++ online submissions for 3Sum Closest.
// O(n^2) 풀이법임.
// 정렬한담에 먼저 작은거 2개 뽑고 나머지 하나를 골랐을 때 target과의 거리 최소값을(local_closest) 미리 구해놓은 look_up_table 을 보고 알아낸다.
// 이 때, 무조건 table 보면 안되고 약간의 제약조건을 걸어줘야함(이거 어려웠음)
// 가지치기를 위해 cut 추가
// 주어진 조건 (그냥 숫자는 -1000~1000 이지만 target은 -10000 ~ 10000)에 따라 test case가 랜덤하게 만들어진다고 가정할 때
// target이 nums의 최소 3개 sum보다 작을 확률 + target이 nums의 최대 3개 sum보다 클 확률이 높으므로 해당 조건 미리 가지치기 처리
// 시간이 그래도 너무 오래걸리는데 시간복잡도를 O(nlogn)정도로 줄일 수 있는 솔루션이 있는건가 싶음... 방법이 떠오르지 않네

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if ((nums[0] + nums[1] + nums[2]) >= target)
            return nums[0] + nums[1] + nums[2];
        else if (nums[len - 3] + nums[len - 2] + nums[len - 1] <= target)
            return nums[len - 3] + nums[len - 2] + nums[len - 1];
        int closest = 13000;
        int ret = 0;
        int i_before, j_before;
        
        int look_up_table[26010];
        for (int i = 0; i <= 26000; i++) look_up_table[i] = 100000;
        for (int i = 0; i < len; i++){
            look_up_table[nums[i] + 13000] = 0;
        }
        for (int i = 0; i <= 26000; i++) {
            if (look_up_table[i] == 0) {
                int cnt = 1;
                for (int j = i - 1; j >= 0; j--) {
                    if (look_up_table[j] == 100000) {
                        look_up_table[j] = cnt++;
                    }
                    else if (look_up_table[j] == 0) {
                        break;
                    }
                    else {
                        look_up_table[j] = abs(look_up_table[j]) > cnt ? cnt : look_up_table[j];
                        cnt++;
                    }
                }
                cnt = -1;
                for (int j = i + 1; j <= 26000; j++) {
                    if (look_up_table[j] == 100000) {
                        look_up_table[j] = cnt--;
                    }
                    else if (look_up_table[j] == 0) {
                        break;
                    }
                    else {
                        look_up_table[j] = abs(look_up_table[j]) > abs(cnt) ? cnt : look_up_table[j];
                        cnt--;
                    }
                }
            }
        }
        bool cut = false;
        for (int i = 0; i < len - 2; i++) {
            if (i != 0 && i_before == nums[i]) continue;
            i_before = nums[i];
            for (int j = i + 1; j < len - 1; j++) {
                if (j != i + 1 && j_before == nums[j]) continue;
                j_before = nums[j];
                int local_closest;
                if (target - nums[i] - nums[j] < nums[j]){
                    local_closest = nums[i] + nums[j] + nums[j + 1] - target;
                    cut = true;
                }
                else if (nums[i] + nums[j] + nums[j + 1] > target){
                    local_closest = nums[i] + nums[j] + nums[j + 1] - target;
                    cut = true;
                }
                else
                    local_closest = look_up_table[target - nums[i] - nums[j] + 13000];
                if (abs(local_closest) < abs(closest)) {
                    closest = local_closest;
                    ret = target + local_closest;
                }
                if (cut == true)
                    break;
            }
            cut = false;
        }
        return ret;
    }
};
