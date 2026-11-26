class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(), ans=0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]=i;
        }
        vector<vector<int>> dp(n, vector<int>(n ,0));
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                int x=arr[i]-arr[j];
                if(mp.contains(x)){
                    int idx=mp[x];
                    if(idx<j){
                        dp[j][i]=max(dp[idx][j],2)+1;
                        ans=max(ans, dp[j][i]);
                    }
                }
            }
        }
        return ans>=3?ans:0;
    }
};
