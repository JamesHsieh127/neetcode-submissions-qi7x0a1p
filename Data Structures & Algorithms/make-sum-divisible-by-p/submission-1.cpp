class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        vector<int> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1]=(prefix[i]+nums[i])%p;
        }
        int ans=n, sum=prefix.back();
        if(sum==0) return 0;
        unordered_map<int, int> mp;
        mp[0]=0;
        for(int i=0; i<=n; i++){
            int target=(prefix[i]-sum+p)%p;
            if(mp.contains(target)){
                ans=min(ans, i-mp[target]);
            }
            mp[prefix[i]]=i;
        }
        return ans==n?-1:ans;
    }
};