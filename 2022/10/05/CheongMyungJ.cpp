//Runtime: 38 ms, faster than 49.54% of C++ online submissions for Wiggle Sort II.
//Memory Usage: 17.3 MB, less than 96.11% of C++ online submissions for Wiggle Sort II.
//시간복잡도 O(n + k) k는 5000, 공간복잡도 o(k)로 풀었음. 공간복잡도 O(1)은 어떻게 하는걸까?

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int array[5001] = {0,};
        
        for (int i = 0; i < nums.size(); i++){
            array[nums[i]]++;
        }
        
        int size = nums.size();
        int index = size - 2 + (size % 2);
        for(int i = 0; i < 5001 ; ){
            if (array[i] == 0) {
                i++;
                continue;
            }
            nums[index] = i;
            array[i]--;
            index -= 2;
            if (index < 0) index = size - 1 - (size % 2);
        }
    }
};
