//Runtime: 8 ms, faster than 42.80% of C++ online submissions for Generate Parentheses.
//Memory Usage: 15.7 MB, less than 23.54% of C++ online submissions for Generate Parentheses.
//dfs로 구현하는데, open, close 개수를 조건을 잘 주어야 함.ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ

class Solution {
public:
    
    void recursive(vector<string>& ret, string parentheses, int depth, int open_depth, int close_depth, int max_depth){
        if (depth == max_depth * 2){
            ret.push_back(parentheses);
            return;
        }

        if (open_depth < max_depth){
                parentheses += '(';
            recursive(ret, parentheses, depth + 1, open_depth + 1,close_depth, max_depth);
            parentheses.pop_back();
        }

        if(open_depth != 0 && close_depth < open_depth) {
            parentheses += ')';
            recursive(ret, parentheses, depth + 1, open_depth , close_depth+1, max_depth);
            parentheses.pop_back();
        }
            
      
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        
        recursive(ret, "", 0,0,0, n);
        return ret;
    }
};
