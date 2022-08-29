//Runtime: 31 ms, faster than 65.79% of C++ online submissions for Min Stack.
//Memory Usage: 16.4 MB, less than 72.03% of C++ online submissions for Min Stack.
//처음엔 이게 가능한건가 싶었는데 pop이 min pop이 아니라 그냥 pop이라서 가능한듯함.
//pair로 저장하는데 first에는 일반 값, second에는 역대 가장 min값을 저장한다.
//이렇게되면 getMin, top은 간단해지므로 생략하고 
//pop을 잘 생각해보면 걍 simple하게 pop하면 역대 가장 최소값도 그에 맞게 pop될것을 예상할 수 있다.
//(만약 top이 getMin과 같으면 같은대로, 다르면 다른대로 min값도 stack 형식으로 저장되어 있음)

class MinStack {
    stack<pair<int, int>> st;
public:
    MinStack() {
        while (st.empty() == false)
            st.pop();
    }

    void push(int val) {
        if (st.empty()) {
            st.push({ val, val });
        }
        else {
            st.push({ val, min(getMin(), val) });
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
