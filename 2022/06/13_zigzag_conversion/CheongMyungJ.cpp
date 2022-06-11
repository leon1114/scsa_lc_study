//Runtime: 8 ms, faster than 85.27% of C++ online submissions for Zigzag Conversion.
//Memory Usage: 8.2 MB, less than 80.03% of C++ online submissions for Zigzag Conversion.


// 수식으로 계산. 맨 윗줄(0번째 줄) 기준으로 아래로n-1, 대각선 위로 n-1 갔다오면 다시 맨 윗줄로 돌아옴. 
// 다음줄 기준으로는 아래로 n-2, 대각선 위로 n-2 갔다오면 돌아오고, 그 다음은 대각선 위로 1, 아래로 1 갔다오면 돌아옴.
// 위에서 k번째 줄(k-1번째 줄)은 2(n-k-1), 2k 반복하여 돌아옴.
// 해당 과정을 numRows만큼만 반복하여 찾으면 모든 문자 확인 가능.
// numRows == 1인 경우엔 2(n-k-1), 2k 모두 0이므로 (k==0) 무한루프에 빠지기 때문에 맨 위에서 s 리턴하도록 처리.

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ret;
        int s_len = s.length();
        for (int i = 0; i < numRows; i++){
            int steps[2] = {2*numRows - 2*(i+1), 2*i};
            int step_idx = 1;
            for (int j = i; j < s_len; j += steps[step_idx]){
                ret += s[j];
                step_idx++;
                step_idx %= 2;
                if (steps[step_idx] == 0){
                    step_idx++;
                    step_idx %= 2;
                }
            }
        }
        return ret;
    }
};

int main(){
  Solution sol;
  string s = "PAYPALISHIRING";
  printf("%s\n", sol.convert(s, 3));
  return 0;
}
