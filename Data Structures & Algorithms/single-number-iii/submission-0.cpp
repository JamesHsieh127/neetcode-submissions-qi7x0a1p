class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        long long xorSum=0, mask=0;
        for(int n:nums){
            xorSum^=n;
        }
        mask=xorSum&((~xorSum)+1);
        for(int n:nums){
            if(n&mask){
                ans[1]^=n;
            }
            else{
                ans[0]^=n;
            }
        }
        return ans;
    }
};