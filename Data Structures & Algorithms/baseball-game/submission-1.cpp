class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int ans=0;
        for(string& s:operations){
            if(s=="C"){
                if(!stk.empty()) stk.pop();
            }
            else if(s=="D"){
                if(!stk.empty()){
                    stk.push(stk.top()*2);
                }
            }
            else if(s=="+"){
                if(stk.size()>1){
                    int x=stk.top();
                    stk.pop();
                    int y=stk.top();
                    stk.push(x);
                    stk.push(x+y);
                }
            }
            else stk.push(stoi(s));
        }
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};