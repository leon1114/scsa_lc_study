//Runtime: 4 ms, faster than 88.19% of C++ online submissions for Count and Say.
//Memory Usage: 7.2 MB, less than 29.71% of C++ online submissions for Count and Say.
//간단하게 재귀로 풀 수 있는 문제

class Solution {
public:
    string recursive(string str, int n){
        if (n == 1)
            return str;
        
        string ret;
        char before_char = 0;
        int same_count = 0;
        for (int i = 0; i < str.length(); i++){
            if (before_char == 0){
                before_char = str[i];
                same_count = 1;
            }
            else{
                if (before_char != str[i]){
                    ret += ('0' + same_count);
                    ret += before_char;
                    before_char = str[i];
                    same_count = 1;
                }
                else{
                    same_count++;
                }
            }
        }
        ret += ('0' + same_count);
        ret += before_char; 
        return recursive(ret, n - 1);
    }
    string countAndSay(int n) {
        return recursive("1", n);
    }
};
