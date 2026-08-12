class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(), sum=0, minSum=INT_MAX, ans=nums[0];
        vector<int> dp(n, INT_MIN), dpMin(n, INT_MAX);
        dp[0]=nums[0];
        dpMin[0]=nums[0];
        for(int i=1; i<n; i++){
            dp[i]=max(nums[i]+dp[i-1], nums[i]);
            dpMin[i]=min(nums[i]+dpMin[i-1], nums[i]);
            ans=max(ans, dp[i]);
        }
        for(int& x:nums) sum+=x;
        for(int& x:dpMin){
            minSum=min(minSum, x);
        }
        if(sum==minSum) return ans;
        return max(ans, sum-minSum);
    }
};