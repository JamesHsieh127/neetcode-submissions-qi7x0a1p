class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> stk;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(i&& s[i]==s[i-1]){
                stk.top()++;
            }
            else{
                stk.push(1);
            }
            if(stk.top()==k){
                stk.pop();
                s.erase(i-k+1, k);
                i-=k;
            }
        }
        return s;
    }
};