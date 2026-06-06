class Solution {
public:
    vector<bool> vis;
    int target=0;
    bool dfs(vector<int>& nums, int k, int start, int curSum){
        if(k==1) return true;
        if(curSum==target) return dfs(nums, k-1, 0 ,0);
        int n=nums.size();
        for(int i=start; i<n; i++){
            if(vis[i]||
            (curSum+nums[i]>target)||
            (i>start&& nums[i]==nums[i-1]&& !vis[i-1])) continue;
            vis[i]=true;
            if(dfs(nums, k, i+1, curSum+nums[i])){
                return true;
            }
            vis[i]=false;
            if(curSum == 0 || curSum+nums[i]==target) {
                return false;
            }
        }    
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0, n=nums.size();
        for(int& x:nums) sum+=x;
        if(sum%k!=0) return false;
        target=sum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[0] > target) return false;
        vis.assign(n, false);
        return dfs(nums, k, 0, 0);
    }
};