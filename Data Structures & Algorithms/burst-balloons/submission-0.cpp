class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        vector<int> vals(n+2, 0);
        vals[0]=1;
        vals.back()=1;
        for(int i=1; i<=n; i++){
            vals[i]=nums[i-1];
        }
        for(int i=n-1; i>=0; i--){
            for(int k=i+2; k<=n+1; k++){
                for(int j=i+1; j<k; j++){
                    int sum=vals[i]*vals[j]*vals[k];
                    sum+=(dp[i][j]+dp[j][k]);
                    dp[i][k]=max(dp[i][k], sum);
                }
            }
        }
        return dp[0].back();
    }
};
