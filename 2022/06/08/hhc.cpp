/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

//Runtime: 7 ms, faster than 91.84% of C++ online submissions for Longest Substring Without Repeating Characters.
//Memory Usage: 6.9 MB, less than 91.23% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int mem [200] = {};
        for (int i=0;i<200;i++)mem[i]=-1;
        int sub_start = -1;
        for(int i = 0; i < s.length(); i++) {
            // s[i]는 charhacter 하나
            //cout<<s[i]<<" last_loc"<<mem[(int)s[i]]<<" loc_len"<<i - sub_start<<" len"<<len<<"\n";
            //(int)s[i]는 character의 ascii number(int)
            //mem[(int)s[i]]는 ascii number가 마지막에 나온 위치
            if (mem[(int)s[i]] < sub_start) {
                mem[(int)s[i]] = sub_start;
            }
            if (mem[(int)s[i]] > sub_start) {
                sub_start = mem[(int)s[i]];
            }
            //cout<<sub_start<<"\n";
            int loc_len = i - sub_start;
           // cout<<loc_len<<"\n";
            if (loc_len > len) len = loc_len;
            mem[(int)s[i]] = i;
        }
        return len;
    }
};

int main()
{
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("dvdf");
    cout<<sol.lengthOfLongestSubstring("a");
    cout<<sol.lengthOfLongestSubstring("aab");
    cout<<sol.lengthOfLongestSubstring("abcabcbb");
    cout<<sol.lengthOfLongestSubstring("bbbbb");
    cout<<sol.lengthOfLongestSubstring("pwwkew");
    cout<<sol.lengthOfLongestSubstring("au");
    
    //char  p  w  w  k  e  w
    //idx   0  1  2  3  4  5
    //l_l   -1 -1 1

    return 0;
}

