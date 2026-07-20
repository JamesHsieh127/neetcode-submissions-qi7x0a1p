class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;
    void dfs(vector<int>& nums){
        int n=nums.size();
        if(path.size()==n){
            ans.push_back(path);
            return;
        }
        for(int i=0; i<n; i++){
            if(i>0&& nums[i-1]==nums[i]&& !vis[i-1]) continue;
            if(!vis[i]){
                path.push_back(nums[i]);
                vis[i]=true;
                dfs(nums);
                path.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vis.assign(n, false);
        dfs(nums);
        return ans;
    }
};