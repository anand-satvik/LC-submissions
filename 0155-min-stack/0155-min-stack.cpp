class MinStack {
public:
    stack<long long> s;  // Use long long to handle overflow
    long long mini;
    
    MinStack() {
        mini = LLONG_MAX;  // Initialize mini to the maximum long long value
    }
    
    void push(int val) {
        if(s.empty()) {
            mini = val;
            s.push(val);
        } else if(val >= mini) {
            s.push(val);
        } else {
            s.push(2LL * val - mini);  // Store a modified value
            mini = val;
        }
    }
    
    void pop() {
        if(s.empty()) return;
        
        long long top = s.top();
        s.pop();
        
        if(top < mini) {  // Indicates mini was updated
            mini = 2LL * mini - top;
        }
        
        if(s.empty()) {
            mini = LLONG_MAX;  // Reset mini when stack is empty
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        
        long long top = s.top();
        if(top < mini) {
            return mini;
        } else {
            return top;
        }
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return mini;
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