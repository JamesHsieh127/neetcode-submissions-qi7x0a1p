class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<int>& nums, int idx){
        int n=nums.size();
        ans.push_back(path);
        for(int i=idx; i<n; i++){
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        if(!n) return {};
        dfs(nums, 0);
        return ans;
    }
};
