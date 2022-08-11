//Runtime: 103 ms, faster than 97.60% of C++ online submissions for Palindrome Partitioning.
//Memory Usage: 49.1 MB, less than 99.42% of C++ online submissions for Palindrome Partitioning.
//재귀로 품.
//특정 index에서 끝까지 가보면서 palindrome인 경우에만 다음 stack으로 들어가도록 하면 완성

class Solution {
public:
    
    bool isPalindrome(string s){
        int start = 0;
        int end = s.length() - 1;
        while (start < end){
            if (s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
    void recursive(string& s, int max, int depth, vector<string>& vt, vector<vector<string>>& ret){
        if (max == depth){
            ret.push_back(vt);
            return;
        }
        for (int i = 1; i <= max - depth; i++){
            if (isPalindrome(s.substr(depth, i))){
                vt.push_back(s.substr(depth, i));
                recursive(s, max, depth + i, vt, ret);
                vt.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> dummy;
        recursive(s, s.length(), 0, dummy, ret);
        return ret;
    }
};
