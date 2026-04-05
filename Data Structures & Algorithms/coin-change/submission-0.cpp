class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        int n=coins.size();
        dp[0]=0;
        for(int x:coins){
            for(int i=x; i<=amount; i++){
                dp[i]=min(dp[i], dp[i-x]+1);
            }
        }
        if(dp.back()==amount+1){
            return -1;
        }
        return dp.back();
    }
};
