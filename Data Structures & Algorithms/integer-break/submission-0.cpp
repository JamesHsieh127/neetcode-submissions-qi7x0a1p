class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        for(int i=2; i<=n; i++){
            int curMax=0;
            for(int j=1; j<i; j++){
                curMax=max({curMax, j*(i-j), dp[j]*(i-j)});
            }
            dp[i]=curMax;
        }
        return dp.back();
    }
};