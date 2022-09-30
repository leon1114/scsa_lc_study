//Runtime: 536 ms, faster than 49.61% of C++ online submissions for Sliding Window Maximum.
//Memory Usage: 194.3 MB, less than 9.80% of C++ online submissions for Sliding Window Maximum.
//window 안의 숫자들을 저장해놓을건데 value, index pair로 저장함. 이건 value 내림차순, index는 무조건 오름차순인 순서로 저장되어야 함
//새로운 윈도우(한칸오른쪽)으로 가게 되면 첫번째(value가 가장큰놈)가 버려지는 index인지 확인 먼저 하고 (38line) 위 정렬순서 유지되게 추가함
//다 했으면 front를 ret 배열에 저장.
//이 방법은 운이 좋은경우(nums의 숫자가 계속커지는경우)엔 저장된 숫자가 무조건 하나고, 운이 없는경우(nums가 계속 작아지는경우)엔 저장하기 위한 시간복잡도가 1이라서 최악의 상황은 모면할 수 있음.

using namespace std;
class Solution {
    struct DataSet {
        int val;
        int index;
        DataSet(int a, int b) : val(a), index(b) {}
    };
public:

    void update(int val, list<DataSet>& lst, int index) {
        list<DataSet>::reverse_iterator iter = lst.rbegin();
        int order = 0;
        while (iter != lst.rend()) {
            if (iter->val > val) break;
            order++;
            iter++;
        }
        for (int i = 0; i < order; i++) {
            lst.pop_back();
        }
        lst.push_back(DataSet(val, index));
    }

    int updateQueue(vector<int>& nums, list<DataSet>& lst, int start, int k) {
        int ret = nums[start + k - 1];
        int temp = ret;
        if (lst.size() == 0) {
            lst.push_back(DataSet(ret, start));
            return ret;
        }
        if (lst.front().index < start) lst.pop_front();

        update(temp, lst, start + k - 1);

        ret = lst.front().val;
        return ret;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        list<DataSet> lst;

        for (int i = 0; i < k - 1; i++) {
            update(nums[i], lst, i);
        }
        for (int i = 0; i < nums.size() - k + 1; i++) {
            ret.push_back(updateQueue(nums, lst, i, k));
        }
        return ret;
    }
};
