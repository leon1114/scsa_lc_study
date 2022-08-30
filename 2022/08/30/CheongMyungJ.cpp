//Runtime: 3 ms, faster than 92.40% of C++ online submissions for Find Peak Element.
//Memory Usage: 8.7 MB, less than 89.76% of C++ online submissions for Find Peak Element.
//이진탐색으로 O(logn)으로 해결가능.


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

        int first = 1;
        int second = nums.size() - 2;
        while (first < second) {
            int mid = (first + second) / 2;
            if (nums[mid] > nums[mid + 1] &&
                nums[mid] > nums[mid - 1]) {
                return mid;
            }
            if (first == mid) return second;
            if (nums[first] < nums[mid]) {
                if (nums[mid - 1] > nums[mid]) {
                    second = mid - 1;
                }
                else {
                    first = mid + 1;
                }
            }
            else {
                second = mid - 1;
            }
        }
        return first;
    }
};
