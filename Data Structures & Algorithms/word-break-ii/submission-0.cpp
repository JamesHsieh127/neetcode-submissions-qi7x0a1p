class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> st;
        for(auto& a:wordDict) st.insert(a);
        vector<vector<string>> dp(n+1);
        dp[0]={""};
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                string word=s.substr(j, i-j);
                if(!dp[j].empty()&&
                st.contains(word)){
                    for(auto& prev:dp[j]){
                        if(prev==""){
                            dp[i].push_back(word);
                        }
                        else{
                            dp[i].push_back(prev+" "+word);
                        }
                    }
                }
            }
        }
        return dp.back();
    }
};