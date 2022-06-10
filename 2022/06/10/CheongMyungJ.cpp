//Runtime: 37 ms, faster than 73.71% of C++ online submissions for Longest Palindromic Substring.
//Memory Usage: 7.2 MB, less than 81.90% of C++ online submissions for Longest Palindromic Substring.
//시간복잡도 O(n^2)방법.

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int max_len = 1;
        int tmp_len; // 임시로 길이 잴 변수
        int med_index = 0; // 이 인덱스 기준으로 양옆으로 펼쳐봄
        for (int i = 0; i < len; i++){ // 전체 한번 쭉 돌면서
            tmp_len = 1; // 하나의 문자 기준 (홀수)
            for (int j = 1; i + j < len && i - j >= 0; j++){ // 양옆으로 쭉 비교해서 다르면 나가기
                if (s[i + j] != s[i - j]){
                    break;
                }
                else {
                    tmp_len = j * 2 + 1;
                }
            }
            if (tmp_len > max_len){ // 길이 업데이트
                max_len = tmp_len;
                med_index = i;
            }
            if (i + 1 < len && s[i] == s[i + 1]){ // 만약 다음 문자가 현재 문자랑 같다면
                tmp_len = 2; // 두개 문자 기준 (짝수)
                for (int j = 1; i + j + 1 < len && i - j >= 0; j++){ // 양옆으로 쭉 비교해서 다르면 나가기
                    if (s[i + 1 + j] != s[i - j]){
                        break;
                    }
                    else{
                        tmp_len = (j + 1) * 2;
                    }
                }
                if (tmp_len > max_len){ // 길이 업데이트
                    max_len = tmp_len;
                    med_index = i;
                }   
            }
        }
        return s.substr(med_index - (max_len - 1) / 2, max_len);
    }
};
