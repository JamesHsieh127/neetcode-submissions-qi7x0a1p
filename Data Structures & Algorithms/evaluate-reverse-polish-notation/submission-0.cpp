class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        int n=tokens.size();
        for(int i=0; i<n; i++){
            if(tokens[i]=="+"||tokens[i]=="-"||
            tokens[i]=="*"||tokens[i]=="/"){
                int y=stk.top();
                stk.pop();
                int x=stk.top();
                stk.pop();
                if(tokens[i]=="+"){
                    stk.push((long long)x+y);
                }
                if(tokens[i]=="-"){
                    stk.push((long long)x-y);
                }
                if(tokens[i]=="*"){
                    stk.push((long long)x*y);
                }
                if(tokens[i]=="/"){
                    stk.push((long long)x/y);
                }
            }
            else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
