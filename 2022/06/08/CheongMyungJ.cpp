#include <stdio.h>
#include <string>

using namespace std;


// 한번 string.length()만큼 훑으면서 동일한 char가 나오면(check_arr[s[i]] != -1) 이전에 해당 char가 나왔던 위치 이전까지의 기록을 삭제하고 (29~32line)
// 계속 진행. n*2만큼의 수행시간( O(n) )
// Runtime: 3 ms, faster than 98.60% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 6.8 MB, less than 96.65% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int check_arr[256 + 10];
        for (int i = 0; i < 256 + 10; i++)
            check_arr[i] = -1;
        int start_index = 0;
        int max_len = 0;
        int len = 0;

        int s_len = s.length();
        for (int i = 0; i < s_len; i++) {
            if (check_arr[s[i]] == -1) {
                check_arr[s[i]] = i;
                len++;
            }
            else {
                for (int j = start_index; j < check_arr[s[i]]; j++) {
                    check_arr[s[j]] = -1;
                }
                start_index = check_arr[s[i]] + 1;
                check_arr[s[i]] = i;
                if (max_len < len) {
                    max_len = len;
                }
                len = i - start_index + 1;
            }
        }
        if (max_len < len)
            max_len = len;

        return max_len;
    }
};


int main() {
	
    string st = "abcabcbb";
    Solution sol;
    printf("%d\n",sol.lengthOfLongestSubstring(st));
	return 0;
}

