class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n+1, 0);
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0; i<=n; i++){
            int rem=prefix[i]%k;
            if(mp.contains(rem)){
                if(i-mp[rem]>=2){
                    return true;
                }
            }
            else{
                mp[rem]=i;
            }
        }
        return false;
    }
};