class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int n=s.size(), x=0, ans=0;
        char preSign='+';
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                x=x*10+(s[i]-'0');
            }
            if((!isdigit(s[i])&&s[i]!=' ')||
            i==n-1){
                if(preSign=='+'){
                    stk.push(x);
                }
                else if(preSign=='-'){
                    stk.push(-x);
                }
                else if(preSign=='*'){
                    int y=stk.top();
                    stk.pop();
                    stk.push(y*x);
                }
                else if(preSign=='/'){
                    int y=stk.top();
                    stk.pop();
                    stk.push(y/x);
                }
                x=0;
                preSign=s[i];
            }
        }
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};