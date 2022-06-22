#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// Runtime: 39 ms, faster than 5.91% of C++ online submissions for Generate Parentheses.
// Memory Usage: 25.3 MB, less than 5.56% of C++ online submissions for Generate Parentheses.
class Solution {
public:
    vector<string> hanoi(string s, int open_stack, int n, int closed) {
        vector<string> ret;
        vector<string> tmp;
        string s_tmp;
        
        if (!open_stack && closed == n) {
            ret.insert(ret.begin(), s);
            return ret;
        }
        
        // open_stack < n, Append '(', then dfs
        if (open_stack + closed < n) {
            s_tmp = s;
            s_tmp += '(';
            tmp = hanoi(s_tmp, open_stack + 1, n, closed);
            ret.insert(ret.end(), tmp.begin(), tmp.end());
        }

        // open_stack > 0, Append ')', then dfs
        if (open_stack > 0) {
            s_tmp = s;
            s_tmp += ')';
            tmp = hanoi(s_tmp, open_stack - 1, n, closed + 1);
            ret.insert(ret.end(), tmp.begin(), tmp.end());
        }
        return ret;
    }
    vector<string> generateParenthesis(int n) {
        return hanoi("", 0, n, 0);
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
