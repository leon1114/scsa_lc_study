// Runtime: 263 ms, faster than 16.05% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 47.4 MB, less than 32.63% of C++ online submissions for Kth Largest Element in an Array.
// 우큐는 O(n)이 아닌듯..?

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
