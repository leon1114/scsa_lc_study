//Runtime: 19 ms, faster than 75.75% of C++ online submissions for Minimum Window Substring.
//Memory Usage: 7.6 MB, less than 93.81% of C++ online submissions for Minimum Window Substring.
//우선 t를 돌면서 모든 문자의 count를 저장. (t_char_cnt)
//그다음 s를 돌면서 t_char_cnt값이 0보다 큰놈이면(t에 있는 놈이면) 해당 문자 count를 증가(s_char_cnt)
//t_char_cnt와 s_char_cnt가 동일해지는 시점이 (s_cnt==t_len) 답이 될 가능성이 있는 sub set
//end 기준을 s끝까지 가면서 start 기준을 뒤로 땡길 수 있으면 땡겨보고(s_char_cnt[s[start]] > t_char_cnt[s[start]])
//새로 구해진 sub set의 길이를 재본 다음 더 작으면 update
//O(2n+m) = O(n+m)방법


class Solution {
public:
    string minWindow(string s, string t) {
        int t_char_cnt[123] = { 0, };
        int s_char_cnt[123] = { 0, };
        int t_len = t.length();
        int s_cnt = 0;
        for (int i = 0; i < t_len; i++) {
            t_char_cnt[t[i]]++;
        }
        int start = -1; 
        int end = -1;
        int min_len = 100000;
        int s_start = -1;
        int s_end = -1;
        for (int i = 0; i < s.length(); i++) {
            if (t_char_cnt[s[i]] > 0) {
                if (start == -1) start = i;
                end = i;
                if (t_char_cnt[s[i]] > s_char_cnt[s[i]]) s_cnt++;
                s_char_cnt[s[i]]++;
            }
            if (s_cnt == t_len) {
                while (s_char_cnt[s[start]] > t_char_cnt[s[start]]) {
                    s_char_cnt[s[start]]--;
                    for (int j = start + 1; j < end; j++) {
                        if (t_char_cnt[s[j]] > 0) {
                            start = j;
                            break;
                        }
                    }
                }
                if (end - start + 1 < min_len) {
                    s_start = start;
                    s_end = end;
                    min_len = end - start + 1;
                }
            }
        }
        if (s_cnt == t_len) {
            return s.substr(s_start, s_end - s_start + 1);
        }
        return "";
    }
};
