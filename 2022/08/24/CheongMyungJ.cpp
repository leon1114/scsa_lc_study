//Runtime: 12 ms, faster than 79.82% of C++ online submissions for Evaluate Reverse Polish Notation.
//Memory Usage: 12.1 MB, less than 19.62% of C++ online submissions for Evaluate Reverse Polish Notation.
//숫자는 스택에 넣고, 연산자가 나오면 스택에서 두개 꺼내서 연산 후 결과를 다시 스택에 넣음.
//문제에 인트범위를 보장한다는 말이 없어서 문자열로 풀어야하나 했지만
//리턴이 인트라 걍 해봤는데 되네 개꿀 ㅎ;

class Solution {
    unordered_set<string> operand = { "+", "-", "*", "/" };
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (int i = 0; i < tokens.size(); i++) {
			if (operand.count(tokens[i]) > 0) {
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				if (tokens[i] == "+") {
					st.push(left + right);
				}
				else if (tokens[i] == "-") {
					st.push(left - right);
				}
				else if (tokens[i] == "*") {
					st.push(left * right);
				}
				else {
					st.push(left / right);
				}
			}
			else {
				int num = stoi(tokens[i]);
				st.push(num);
			}
		}
		return st.top();
	}
};
