#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// 뭐지 왤케 느리지..? 어케 빨리하누 string += char; 요게 느린덧?
// Runtime: 16 ms, faster than 12.94% of C++ online submissions for Generate Parentheses.
// Memory Usage: 15.8 MB, less than 19.88% of C++ online submissions for Generate Parentheses.
class Solution {
public:
    vector<string> sol;
    void hanoi(string s, int open_stack, int n, int closed) {
        string s_tmp;
        if (!open_stack && closed == n) {
            sol.insert(sol.end(), s);
        }
        
        // open_stack < n, Append '(', then dfs
        if (open_stack + closed < n) {
            s_tmp = s;
            s_tmp += '(';
            hanoi(s_tmp, open_stack + 1, n, closed);
        }

        // open_stack > 0, Append ')', then dfs
        if (open_stack > 0) {
            s_tmp = s;
            s_tmp += ')';
            hanoi(s_tmp, open_stack - 1, n, closed + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        hanoi("", 0, n, 0);
        return sol;
    }
};


int main()
{
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);
    for (auto const& s: res) {
        cout << s << " / ";
    }
    cout << endl;
    return 0;
}
