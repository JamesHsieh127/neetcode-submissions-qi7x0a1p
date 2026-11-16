class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        unordered_map<int,int> cnt;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int diff=i-nums[i];
            int good=cnt[diff];
            ans+=(i-good);
            cnt[diff]=good+1;
        }
        return ans;
    }
};
