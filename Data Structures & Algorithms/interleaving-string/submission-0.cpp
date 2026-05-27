class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(), m=s2.size();
        if(n+m!=s3.size()) return false;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0]=true;
        for(int i=0; i<n; i++){
            dp[i+1][0]=(dp[i][0]&&s1[i]==s3[i]);
        }
        for(int j=0; j<m; j++){
            dp[0][j+1]=(dp[0][j]&&s2[j]==s3[j]);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i+1][j+1]=(
                    (dp[i][j+1]&&s1[i]==s3[i+j+1])||
                    (dp[i+1][j]&&s2[j]==s3[i+j+1])
                );
            }
        }
        return dp[n][m];
    }
};
