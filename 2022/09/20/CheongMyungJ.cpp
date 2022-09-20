//Runtime: 8 ms, faster than 89.69% of C++ online submissions for Basic Calculator II.
//Memory Usage: 8.6 MB, less than 48.31% of C++ online submissions for Basic Calculator II.
//후위연산자 방식 stack 사용. 곱셈 나눗셈은 바로바로 처리하게 
class Solution {
public:

	int findNumber(string& s, int& i, bool is_minus = false) {
		while (s[i] == ' ') { i++; }
		int temp = s[i] - '0';
		for (int j = i + 1; j < s.length(); j++) {
			if (s[j] < '0' || s[j] > '9')
				break;
			temp *= 10;
			temp += s[j] - '0';
			i = j;
		}
		return is_minus ? -temp : temp;
	}

	int calculate(string s) {
		stack<int> num;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') continue;
			if (s[i] >= '0' && s[i] <= '9') {
				num.push(findNumber(s, i));
			}
			else if (s[i] == '-') {
				i++;
				num.push(findNumber(s, i, true));
			}
			else if (s[i] == '*') {
				i++;
				int right = findNumber(s, i);
				int left = num.top();
				num.pop();
				num.push(left * right);
			}
			else if (s[i] == '/') {
				i++;
				int right = findNumber(s, i);
				int left = num.top();
				num.pop();
				num.push(left / right);
			}
		}
		int sum = 0;
		while (num.empty() == false) {
			sum += num.top();
			num.pop();
		}
		return sum;
	}
};
