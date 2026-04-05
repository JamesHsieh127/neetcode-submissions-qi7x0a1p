class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(!n) return "";
        string ans=strs[0];
        int m=ans.size();
        for(int i=0; i<m; i++){
            for(string& s:strs){
                if(i==s.size()||
                s[i]!=ans[i]){
                    return ans.substr(0, i);
                }
            }
        }
        return ans;
    }
};