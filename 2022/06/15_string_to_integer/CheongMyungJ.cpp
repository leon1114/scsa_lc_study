//Runtime: 0 ms, faster than 100.00% of C++ online submissions for String to Integer (atoi).
//Memory Usage: 7 MB, less than 88.89% of C++ online submissions for String to Integer (atoi).
//앞에 공백이면 넘어가고 숫자면 플래그 세우고 부호여도 플래그 세우고 문자면 멈춤
//플래그 세워져있으면 그다음부턴 숫자인 경우에만 10곱하고 해당 숫자 더함(혹은 뺌)
//연산 결과가 int 범위 넘어가면 범위에 맞추고 멈춤

class Solution {
public:
    int myAtoi(string s) {
        bool meet_digit = false;
        int sign = 1;
        int len = s.length();
        long long int num = 0;
        for (int i = 0; i < len; i++){
            if (meet_digit == true){
                if (s[i] >= '0' && s[i] <= '9'){
                    num *= 10;
                    num += ((s[i] - '0') * sign);
                    if (num >= 0x7fffffff){
                        num = 0x7fffffff;
                        break;
                    }
                    else if (num <= (int)0x80000000){
                        num = (int)0x80000000;
                        break;
                    }
                }
                else{
                    break;
                }
            }
            else{
                if (s[i] == ' ') continue;
                else if (s[i] >= '0' && s[i] <= '9'){
                    sign = 1;
                    num = s[i] - '0';
                    meet_digit = true;
                }
                else if (s[i] == '+'){
                    sign = 1;
                    meet_digit = true;
                }
                else if (s[i] == '-'){
                    sign = -1;
                    meet_digit = true;
                }
                else{
                    break;
                }
            }
        }
        return num;
    }
};
