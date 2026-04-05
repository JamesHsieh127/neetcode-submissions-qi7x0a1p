class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int& x:nums) sum+=x;
        if(abs(target)>sum) return 0;
        if((sum+target)&1) return 0;
        int sumP=(sum+target)/2;
        vector<int> dp(sumP+1, 0);
        dp[0]=1;
        for(int& x:nums){
            for(int i=sumP; i>=x; i--){
                dp[i]+=dp[i-x];
            }
        }
        return dp.back();
    }
};
