class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int> stk;
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]=='(') stk.push(i);
            else if(s[i]==')'){
                if(!stk.empty()) stk.pop();
                else s[i]='#';
            }
        }
        while(!stk.empty()){
            s[stk.top()]='#';
            stk.pop();
        }
        for(char& c:s){
            if(c=='#') continue;
            ans+=c;
        }
        return ans;
    }
};
