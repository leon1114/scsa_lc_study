//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Break.
//Memory Usage: 7.9 MB, less than 84.24% of C++ online submissions for Word Break.
//dynamic program
//작은 문자열의 길이가 최대 20자인걸 이용.
//우선 작은 문자열들을 key로 하는 hash에 저장해둠. 나중에 문자열을 key로 해서 존재하는지 여부 바로 판단할 수 있게 할 목적.
//만약 긴 문자열(s)의 n번째 길이까지를 만들어 낼 수 있는가?(dp[n])를 알아보려면
// (dp[n-20] == true && s의 n-20~n까지의 substr이 hash에 존재하는가?) || (dp[n-19] == true && s의 n-19~n까지의 substr이 hash에 존재하는가?) || ....
//의 방식으로 확인할 수 있음.
//결국 s의 길이 N, 작은 문자들의 최대길이 M에 대해 O(N*M)의 시간복잡도로 풀 수 있음.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        int dp[301]{1};
        int s_len = s.length();
        for (int i = 1; i <= s_len; i++) {
            for (int j = i - 1; j > i - 20 && j >= 0; j--) {
                if (dp[j] == true && hash.count(s.substr(j, i - j)) == 1) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s_len] == 0? false : true;
    }
};
