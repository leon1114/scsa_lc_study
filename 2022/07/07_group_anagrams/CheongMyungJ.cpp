//Runtime: 44 ms, faster than 76.96% of C++ online submissions for Group Anagrams.
//Memory Usage: 19.7 MB, less than 74.56% of C++ online submissions for Group Anagrams.
//stl이 참 좋구만...
//각 string을 문자순으로 정렬한 것(문자위치가 다르더라도 정렬하면 하나로 통일 가능)을 key, 같은 key를 갖는 string을 모아둔 vector<string>을 value로 하는 hash 선언
//모든 string에 대해 hash에 때려박기.
//마지막으로 hash를 하나씩 돌면서 vector<string> 꺼내서 리턴할 놈에 push_back


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> hash;
        for (int i = 0; i < strs.size(); i++){
            string dummy = strs[i];
            sort(dummy.begin(), dummy.end());
            hash[dummy].push_back(strs[i]);
        }
        unordered_map<string, vector<string>>::iterator iter = hash.begin();
        while(iter != hash.end()){
            ret.push_back((*iter++).second);
        }
        return ret;
    }
};
