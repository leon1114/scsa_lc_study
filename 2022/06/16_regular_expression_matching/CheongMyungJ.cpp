//Runtime: 147 ms, faster than 17.07% of C++ online submissions for Regular Expression Matching.
//Memory Usage: 6.6 MB, less than 71.58% of C++ online submissions for Regular Expression Matching.
//재귀여서 ㅈㄴ 느린건가... substr때문인가
//p의 다음 문자가 *이 아니면 s랑 단순 비교하고
//p의 다음문자가 *이라면 case 두개로 나눠서 
//현재문자가 .인 경우 반복 0회부터 끝까지 가정하여 재귀로 들어간다.
//현재문자가 .이 아닌경우 해당 문자의 반복횟수를 s에서 구한다음 0회부터 반복횟수만큼 재귀로 들어간다.


class Solution {
public:
    int sameCharacterLength(char first_char, string s, int start_index, int s_len) {
        int ret = 0;
        for (int i = start_index; i < s_len; i++) {
            if (s[i] == first_char)
                ret++;
            else
                break;
        }
        return ret;
    }

    bool isMatch(string s, string p) {
        int s_index = 0;
        int s_len = s.length();
        int p_len = p.length();
        for (int i = 0; i < p_len; i++, s_index++) {
            if ((i + 1 < p_len && p[i + 1] != '*') || i + 1 == p_len) {
                if (s_index == s_len || (p[i] != '.' && s[s_index] != p[i])) {
                    return false;
                }
            }
            else if (i + 1 < p_len && p[i + 1] == '*') {
                int same_char_len;
                if (p[i] == '.') {
                    same_char_len = s_len - s_index;
                }
                else {
                    same_char_len = sameCharacterLength(p[i], s, s_index, s_len);
                }
                for (int j = s_index; j <= s_index + same_char_len; j++) {
                    if (isMatch(s.substr(j, s_len - j), p.substr(i + 2, p_len - (i + 2))))
                        return true;
                }
                return false;
            }
        }
        if (s_index != s_len)
            return false;
        return true;
    }
};
