class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        if(s.size()&1) return false;
        for(char c:s){
            if(c=='{') stk.push('}');
            else if(c=='[') stk.push(']');
            else if(c=='(') stk.push(')');
            else{
                if(stk.empty() || stk.top()!=c) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};