// https://leetcode.com/problems/min-stack/
class MinStack {
public:
    stack<int> stk;
    int minEl = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if (minEl >= val) {
            stk.push(minEl);
            minEl = val;
        }
        stk.push(val);
    }
    
    void pop() {
        if (stk.top() == minEl) {
            stk.pop();
            minEl = stk.top();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minEl;
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