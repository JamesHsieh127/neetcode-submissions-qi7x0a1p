class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        int available=0, n=customers.size();
        for(auto& a:customers){
            available=max(available, a[0])+a[1];
            ans+=(available-a[0]);
        }
        return ans/n;
    }
};