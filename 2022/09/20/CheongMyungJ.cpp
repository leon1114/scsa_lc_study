//Runtime: 33 ms, faster than 17.98% of C++ online submissions for Basic Calculator II.
//Memory Usage: 9.5 MB, less than 11.56% of C++ online submissions for Basic Calculator II.
//후위연산자 방식 stack 사용. 곱셈 나눗셈은 바로바로 처리하게 

class Solution {
public:

	void findNumber(string& s, int& i, stack<int>& num, bool is_minus = false) {
		while (s[i] == ' ') { i++; }
		int temp = s[i] - '0';
		for (int j = i + 1; j < s.length(); j++) {
			if (s[j] < '0' || s[j] > '9')
				break;
			temp *= 10;
			temp += s[j] - '0';
			i = j;
		}
		num.push(is_minus? -temp : temp);
	}

	int calculate(string s) {
		stack<int> num;
		stack<char> oper;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') continue;
			if (s[i] >= '0' && s[i] <= '9') {
				findNumber(s, i, num);
			}
			else if (s[i] == '+') {
				oper.push(s[i]);
			}
            else if (s[i] == '-') {
                oper.push('+');
                i++;
                findNumber(s, i, num, true);
            }
			else if (s[i] == '*') {
				i++;
				findNumber(s, i, num);
				int right = num.top();
				num.pop();
				int left = num.top();
				num.pop();
				num.push(left * right);
			}
			else if (s[i] == '/') {
				i++;
				findNumber(s, i, num);
				int right = num.top();
				num.pop();
				int left = num.top();
				num.pop();
				num.push(left / right);
			}
		}
		while (oper.empty() == false) {
			int right = num.top();
			num.pop();
			int left = num.top();
			num.pop();
			if (oper.top() == '+') {
				num.push(left + right);
			}
			else if (oper.top() == '-') {
				num.push(left - right);
			}
			oper.pop();
		}
		return num.top();
	}
};
