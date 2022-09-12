퇴근을 지금해서 폰으로 대충함ㅜㅜ 정렬기준을, 좀 더 다듬어야,패스될듯

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vt;
        for ( int i = 0; i< nums.size(); i++){
            vt.push_back(to_string(nums[i]));
    }
                         sort(vt.begin(), vt.end());
                         string ret;
              for (int i = vt.size() -1; i >= 0; i--){
                  ret += vt[i];
                  }
                         return ret;
                         }
};
