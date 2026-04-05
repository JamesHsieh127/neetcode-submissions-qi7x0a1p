class MinStack {
public:
    stack<int> stk, minStk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(!minStk.empty()){
            minStk.push(min(minStk.top(), val));
        }
        else{
            minStk.push(val);
        }
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        if(!minStk.empty()){
            return minStk.top();
        }
        else{
            return INT_MAX;
        }
    }
};
