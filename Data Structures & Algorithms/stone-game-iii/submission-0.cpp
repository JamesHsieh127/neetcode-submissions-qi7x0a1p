class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            dp[i]=INT_MIN;
            int sum=0;
            for(int j=i; j<min(i+3, n); j++){
                sum+=stoneValue[j];
                dp[i]=max(dp[i], sum-dp[j+1]);
            }
        }
        int diff=dp[0];
        if(diff==0) return "Tie";
        return diff>0? "Alice":"Bob";
    }
};