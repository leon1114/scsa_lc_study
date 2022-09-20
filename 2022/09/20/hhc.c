// Runtime: 9 ms, faster than 86.45% of C++ online submissions for Basic Calculator II.
// Memory Usage: 7.7 MB, less than 97.55% of C++ online submissions for Basic Calculator II.

class Solution {
public:
    int calculate(string s) {
    int n = s.length();
    
    int ans = 0, lastn = 0, currn = 0;
    char sign = '+';
    
    for(int i=0; i<n; ++i){
        if(isdigit(s[i])) currn = currn * 10 + (s[i] - '0');
        
        if(!isdigit(s[i]) and !isspace(s[i]) or i == n-1){
            if(sign == '+' or sign == '-'){
                ans += lastn;
                lastn = (sign == '+' ? currn : -currn);
            } else if(sign == '*') {
                lastn = lastn * currn;
            } else {
                lastn = lastn / currn;
            }
            currn = 0;
            sign = s[i];
        }
    }
    
    ans += lastn;
    return ans;
}
};
