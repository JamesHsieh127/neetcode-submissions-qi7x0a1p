class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX/2));
        dp[0][1]=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i+1][j+1]=min(dp[i+1][j], dp[i][j+1])+grid[i][j];
            }
        }
        return dp[m][n];
    }
};