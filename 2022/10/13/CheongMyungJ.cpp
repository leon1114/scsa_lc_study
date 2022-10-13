//Runtime: 19 ms, faster than 84.81% of C++ online submissions for Top K Frequent Elements.
//Memory Usage: 13.9 MB, less than 26.14% of C++ online submissions for Top K Frequent Elements.
// n : nums의 크기, m : 2만이라고 하면 O(mlogm)방식

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int check[20001]{};
        for (int i = 0; i < nums.size(); i++)
            check[nums[i] + 10000]++;

        multimap<int, int> mp;
        for (int i = 0; i < 20001; i++)
            if (check[i] > 0)
                mp.insert({check[i], i - 10000});

        vector<int> ret;
        map<int, int>::reverse_iterator iter = mp.rbegin();
        int counter = 0;
        while (counter < k) {
            ret.push_back(iter->second);
            iter++;
            counter++;
        }
        return ret;
    }
};
