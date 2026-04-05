class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> isUsed;
    void dfs(vector<int>& nums){
        int n=nums.size();
        if(path.size()==n){
            ans.push_back(path);
            return;
        }
        for(int i=0; i<n; i++){
            if(isUsed[i]) continue;
            path.push_back(nums[i]);
            isUsed[i]=true;
            dfs(nums);
            path.pop_back();
            isUsed[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        this->isUsed=vector<bool>(n, false);
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ans;
    }
};
