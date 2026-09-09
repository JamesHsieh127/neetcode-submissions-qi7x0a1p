class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(), ans=0;
        vector<int> prefix(n+1, 0);
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0; i<=n; i++){
            int x=((prefix[i]%k)+k)%k;
            ans+=mp[x];
            mp[x]++;
        }
        return ans;
    }
};