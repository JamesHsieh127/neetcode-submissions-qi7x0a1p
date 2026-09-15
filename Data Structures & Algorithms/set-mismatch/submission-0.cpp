class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(2, -1);
        unordered_map<int, int> cnt;
        for(int i=0; i<n; i++){
            cnt[nums[i]]++;
        }
        for(int i=1; i<=n; i++){
            if(cnt[i]>1) ans[0]=i;
            if(cnt[i]<1) ans[1]=i;
        }
        return ans;
    }
};