class Solution {
public:
    int ans=0;
    void dfs(vector<int>& nums, int target, int sum){
        int n=nums.size();
        if(sum>=target){
            if(sum==target) ans++;
            return;
        }
        for(int i=0; i<n; i++){
            dfs(nums, target, sum+nums[i]);
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        dfs(nums, target, 0);
        return ans;
    }
};