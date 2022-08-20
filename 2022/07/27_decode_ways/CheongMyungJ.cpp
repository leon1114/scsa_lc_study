//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
//Memory Usage: 6.2 MB, less than 72.91% of C++ online submissions for Decode Ways.
//dp문제같아서 dp로 품. 
//2칸 전 상태에서 현 상태로 올 수 있으려면 2자리 숫자가 변환가능해야함. 
//1칸 전 상태에서 현 상태로 올 수 있으려면 1자리 숫자가 변환가능해야함.
//현 상태의 경우의수는 2칸전 상태의 경우의수(가능한경우) + 1칸전 상태의 경우의수(가능한경우) 이므로
//그 방식대로 dp구현.

class Solution {
public:
    int convertable(char a, char b, int mode = 1){
        if (mode == 1){
            if (a >= '1' && a <= '9') return 1;
            else return 0;
        }
        else if (mode == 2){
            if ((a == '1' && b >= '0' && b <= '9') || (a == '2' && b >= '0' && b <= '6'))
                return 1;
            else return 0;
        }
        return 0;
    }
    int numDecodings(string s) {
        int dp[101] = {0,};
        if (s.length() == 1)
            return convertable(s[0], 0);
        
        dp[0] = convertable(s[0], 0);
        dp[1] = convertable(s[0], s[1], 2) + dp[0] * convertable(s[1], 0);
        
        
        for (int i = 2; i < s.length(); i++){
            dp[i] = dp[i-2] * convertable(s[i-1], s[i], 2) + dp[i-1] * convertable(s[i], 0);
        }
        return dp[s.length() - 1];
        
    }
};
