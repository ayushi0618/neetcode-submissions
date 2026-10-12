#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<int> s;
    std::stack<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        if (!s.empty()) {
            s.pop();
            minStack.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};