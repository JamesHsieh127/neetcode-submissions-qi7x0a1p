class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(char& c:num){
            while(k&& !ans.empty()&& ans.back()>=c){
                k--;
                ans.pop_back();
            }
            ans.push_back(c);
        }
        while(k){
            k--;
            ans.pop_back();
        }
        int n=ans.size(), i=0;
        while(i<n&& ans[i]=='0') i++;
        ans=ans.substr(i);
        return ans==""?"0":ans;
    }
};
