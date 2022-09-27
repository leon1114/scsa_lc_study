//Runtime: 247 ms, faster than 38.23% of C++ online submissions for Find the Duplicate Number.
//Memory Usage: 61.3 MB, less than 62.13% of C++ online submissions for Find the Duplicate Number.
//이것도 constant로 쳐주나? ㅠㅠ xor 이용해서 풀고싶었는데 중복숫자가 3개 이상일수도 있어서 어떻게해야할지 모르겠네,,,
//아래는 중복숫자가 딱 2개일때 xor로 푸는 방법


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        char arr[12501]{};
        for (int i = 0; i < nums.size(); i++){
            if (((arr[nums[i]/8]) & (1 << (nums[i]%8))) > 0) return nums[i];
            arr[nums[i]/8] += (1 << (nums[i]%8));
        }
        return 0;                
    }
};


중복숫자가 딱 2개일때 xor로 푸는 방법
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sol = 0;
        for (int i = 1; i < nums.size() - 1; i++){
            sol ^= i;
            sol ^= nums[i];
        }
        return sol;                
    }
};
