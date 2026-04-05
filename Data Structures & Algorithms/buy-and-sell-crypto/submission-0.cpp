class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, minPrice=prices[0], n=prices.size();
        for(int i=1; i<n; i++){
            profit=max(profit, prices[i]-minPrice);
            minPrice=min(minPrice, prices[i]);
        }
        return profit;
    }
};
