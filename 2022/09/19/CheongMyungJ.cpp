//Runtime: 72 ms, faster than 99.89% of C++ online submissions for Kth Largest Element in an Array.
//Memory Usage: 45.4 MB, less than 87.30% of C++ online submissions for Kth Largest Element in an Array.
//배열은 10만개지만 숫자범위는 2만개라서 O(n + m)으로 처리함 여기서 n은 최대 10만, m은 2

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int arr[20001]{};
        
        int max = -10000;
        vector<int>::iterator it = nums.begin();
        while (it != nums.end()){
            arr[*it + 10000]++;
            if (max < *it)
                max = *it;
            it++;
        }
        int sum = 0;
        for (int i = max + 10000; i >= 0; i--){
            sum += arr[i];
            if (sum >= k)
                return i - 10000;
        }
        return 0;
    }
};
