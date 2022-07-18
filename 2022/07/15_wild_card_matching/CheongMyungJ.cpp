//Runtime: 34 ms, faster than 90.12% of C++ online submissions for Wildcard Matching.
//Memory Usage: 6.6 MB, less than 95.62% of C++ online submissions for Wildcard Matching.
//하다보니 코너케이스가 많이 생겨서 코드가 더러워짐..
//*기준으로 p를 쪼개서 string 배열을 만든다. (sub_str)
//쪼개진 string을 기준으로 s와 비교한다.
//첫째, 마지막 string은 정확히 시작점,끝점 기준으로 일치해야 하고 1), 3)
//중간 string은 s기준을 하나씩 오른쪽으로 옮겨가면서 가능한 위치를 찾는다. 2)
//끝까지 갔을 때 원하는 조합을 얻을 수 없으면 false. 

class Solution {
public:

    bool strncmp(const char* a, string b, int n) {
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && b[i] != '?')
                return false;
        }
        return true;
    }

    bool isMatch(string s, string p) {
        const char* char_s = s.c_str();

        int s_len = s.length();
        int p_len = p.length();
        string sub_str[2001];
        int sub_str_count = 0;
        int s_index = 0;
        bool test = false;

        for (int i = 0; i < p_len; i++) {
            if (p[i] != '*')
                sub_str[sub_str_count] += p[i];
            else
                sub_str_count++;
        }

        for (int i = 0; i <= sub_str_count; i++) {
            if (s_index > s_len - sub_str[i].length() || s_len - (int)sub_str[i].length() < 0) ////// 1) 첫,끝문자를 비교할 수 있게 하는 조건
                return false;

            if (i == 0) { /////// 3) 첫문자
                if (strncmp(char_s, sub_str[i], sub_str[i].length()) == false)
                    return false;
                s_index += sub_str[i].length();
            }
            else if (i == sub_str_count) { /////// 3) 끝문자
                if (strncmp(char_s + s_len - sub_str[i].length(), sub_str[i], sub_str[i].length()) == false)
                    return false;
                s_index = s_len;
            }
            else { /////// 2) 중간문자들. 안되면 한칸씩 오른쪽으로 이동. 만약 **이면 sub_str[i].length()는 0이므로 이 땐 무조건 true
                test = sub_str[i].length() == 0? true : false;
                for (int j = s_index; j < s_len; j++) {
                    if (strncmp(char_s + j, sub_str[i], sub_str[i].length()) == true) {
                        s_index = j + sub_str[i].length();
                        test = true;
                        break;
                    }
                }
                if (test == false)
                    return false;
            }
        }
        if (s_index != s_len)
            return false;
        return true;
    }
};
