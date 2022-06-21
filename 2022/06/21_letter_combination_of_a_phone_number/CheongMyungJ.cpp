//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
//Memory Usage: 6.2 MB, less than 99.65% of C++ online submissions for Letter Combinations of a Phone Number.
//허허....

class Solution {
public:
    string numberToString(char num){
        if (num == '2')
            return "abc";  
        else if (num == '3')
            return "def";
        else if (num == '4')
            return "ghi";
        else if (num == '5')
            return "jkl";
        else if (num == '6')
            return "mno";
        else if (num == '7')
            return "pqrs";
        else if (num == '8')
            return "tuv";
        else if (num == '9')
            return "wxyz";
        
        return "";
    }
    vector<string> letterCombinations(string digits) {\
        vector<string> ret;
        string st_arr[4];
        int len = digits.length();
        
        for (int i = 0; i < len; i++){
            string st = numberToString(digits[i]);
            st_arr[i] = st;
        }
        for (int i = 0; i < st_arr[0].length(); i++){
            for (int j = 0; j < st_arr[1].length(); j++){
                for (int k = 0; k < st_arr[2].length(); k++){
                    for (int l = 0; l < st_arr[3].length(); l++){
                        string temp;
                        temp += st_arr[0][i];
                        temp += st_arr[1][j];
                        temp += st_arr[2][k];
                        temp += st_arr[3][l];
                        ret.push_back(temp);   
                    }
                    if (st_arr[3].length() == 0){
                        string temp;
                        temp += st_arr[0][i];
                        temp += st_arr[1][j];
                        temp += st_arr[2][k];
                        ret.push_back(temp);
                    }
                }
                if (st_arr[2].length() == 0){
                    string temp;
                    temp += st_arr[0][i];
                    temp += st_arr[1][j];
                    ret.push_back(temp);
                }
            }
            if (st_arr[1].length() == 0){
                string temp;
                temp += st_arr[0][i];
                ret.push_back(temp);
            }
        }
        return ret;
    }
};
