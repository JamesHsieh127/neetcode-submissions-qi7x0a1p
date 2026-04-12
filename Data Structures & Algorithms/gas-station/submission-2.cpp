class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=0, curSum=0, minSum=0, n=gas.size();
        for(int i=0; i<n; i++){
            curSum+=(gas[i]-cost[i]);
            if(curSum<minSum){
                minSum=curSum;
                ans=i+1;
            }
        }
        return curSum>=0?ans:-1;
    }
};
