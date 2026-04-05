class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1, false);
        dp[0]=true;
        unordered_set<string> st;
        for(string& w:wordDict){
            st.insert(w);
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(dp[j]&& st.contains(s.substr(j, i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
