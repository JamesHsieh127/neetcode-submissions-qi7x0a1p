class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        dp[1][1]=INT_MIN;
        for(int i=0; i<n; i++){
            dp[i+2][0]=max(dp[i+1][0], dp[i+1][1]+prices[i]);
            dp[i+2][1]=max(dp[i+1][1], dp[i][0]-prices[i]);
        }
        return dp.back()[0];
    }
};
 