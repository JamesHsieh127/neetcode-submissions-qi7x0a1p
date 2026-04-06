class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay=days.back();
        unordered_set<int> st;
        for(auto& a:days) st.insert(a);
        vector<int> dp(lastDay+1, 0);
        for(int i=1; i<=lastDay; i++){
            if(!st.contains(i)){
                dp[i]=dp[i-1];
            }
            else{
                dp[i]=min({dp[i-1]+costs[0],
                dp[max(0, i-7)]+costs[1],
                dp[max(0, i-30)]+costs[2]});
            }
        }
        return dp.back();
    }
};