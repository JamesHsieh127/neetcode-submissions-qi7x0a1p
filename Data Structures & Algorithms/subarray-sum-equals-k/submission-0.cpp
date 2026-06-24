class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), ans=0;
        vector<int> prefix(n+1, 0);
        unordered_map<int, int> cnt;
        for(int i=0; i<n; i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0; i<=n; i++){
            if(cnt.contains(prefix[i]-k)){
                ans+=(cnt[prefix[i]-k]);
            }
            cnt[prefix[i]]++;
        }
        return ans;
    }
};