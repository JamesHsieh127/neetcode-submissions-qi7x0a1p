class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<int>& nums, int target, int idx){
        int n=nums.size();
        if(0==target){
            ans.push_back(path);
            return;
        }
        if(target<0) return;
        for(int i=idx; i<n; i++){
            path.push_back(nums[i]);
            dfs(nums, target-nums[i], i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(!n) return {};
        dfs(nums, target, 0);
        return ans;
    }
};
