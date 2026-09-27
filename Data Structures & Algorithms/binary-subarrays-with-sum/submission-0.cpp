class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(), ans=0;
        vector<int> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        unordered_map<int, int> cnt;
        for(int& x:prefix){
            if(cnt.contains(x-goal)){
                ans+=cnt[x-goal];
            }
            cnt[x]++;
        }
        return ans;
    }
};