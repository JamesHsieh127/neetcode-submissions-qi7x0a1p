class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(), ans=nums[0];
        vector<int> dp(n, 0), dpN(n, 0);
        dp[0]=nums[0];
        dpN[0]=nums[0];
        for(int i=1; i<n; i++){
            dp[i]=max({dp[i-1]*nums[i], dpN[i-1]*nums[i], nums[i]});
            dpN[i]=min({dp[i-1]*nums[i], dpN[i-1]*nums[i], nums[i]});
            ans=max({ans, dp[i], dpN[i]});
        }
        return ans;
    }
};
