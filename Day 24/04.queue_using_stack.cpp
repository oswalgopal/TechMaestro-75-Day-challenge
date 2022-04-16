// https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.push(x);
        while(!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
    
    int pop() {
        int val = stk1.top();
        stk1.pop();
        return val;
    }
    
    int peek() {
        if (empty()) {
            return -1;
        }
        return stk1.top();
    }
    
    bool empty() {
        return stk1.empty();
    }
};