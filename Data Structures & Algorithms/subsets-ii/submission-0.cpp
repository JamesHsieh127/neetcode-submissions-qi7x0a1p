class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<int>& nums, int idx){
        int n=nums.size();
        ans.push_back(path);
        for(int i=idx; i<n; i++){
            if(i>idx&& nums[i]==nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};
