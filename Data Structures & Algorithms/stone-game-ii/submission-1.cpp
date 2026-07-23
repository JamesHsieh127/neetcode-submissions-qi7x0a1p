class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size(), sum=0;
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            sum+=piles[i];
            for(int m=1; m<=i/2+1; m++){
                if(i+m*2>=n) dp[i][m]=sum;
                else{
                    int minVal=INT_MAX;
                    for(int x=1; x<=m*2; x++){
                        minVal=min(minVal, dp[i+x][max(m, x)]);
                    }
                    dp[i][m]=(sum-minVal);
                }
            }
        }
        return dp[0][1];
    }
};