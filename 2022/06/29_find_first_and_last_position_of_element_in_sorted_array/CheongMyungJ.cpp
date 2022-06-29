//Runtime: 3 ms, faster than 99.04% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
//Memory Usage: 13.7 MB, less than 62.95% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
//이진탐색 하는데, target을 찾고나면 좌측으로, 우측으로 이진탐색을 계속하면서 target을 또 만나면 업데이트한다.
//끗


#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void specialBinarySearch(vector<int>& nums, vector<int>& ret, int start, int end, int target, bool left_search) {
        int median = 0;
        if (left_search == true) {
            while (start <= end) {
                median = (start + end) / 2;
                if (nums[median] < target) {
                    start = median + 1;
                }
                else {
                    ret[0] = median;
                    end = median - 1;
                }
            }
        }
        else {
            while (start <= end) {
                median = (start + end) / 2;
                if (nums[median] > target) {
                    end = median - 1;
                }
                else {
                    ret[1] = median;
                    start = median + 1;
                }
            }
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = { -1, -1 };
        int len = nums.size();
        int start = 0;
        int end = len - 1;
        int median = 0;

        while (start <= end) {
            median = (start + end) / 2;
            if (nums[median] > target) {
                end = median - 1;
            }
            else if (nums[median] < target) {
                start = median + 1;
            }
            else {
                ret[0] = median;
                ret[1] = median;
                specialBinarySearch(nums, ret, start, median - 1, target, true);
                specialBinarySearch(nums, ret, median + 1, end, target, false);
                break;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> vt = { 5, 7, 7, 8, 8, 10 };

    Solution s;
    vector<int> ret = s.searchRange(vt, 8);
    if (ret[0] == 3  && ret[1] == 4)
        cout << "PASS!" << endl;
    else
        cout << "FAIL!" << endl;

}
