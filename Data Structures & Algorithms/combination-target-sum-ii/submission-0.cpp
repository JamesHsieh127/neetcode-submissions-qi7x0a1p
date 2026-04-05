class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<int>& candidates, int target, int idx, int sum){
        int n=candidates.size();
        if(target==sum){
            ans.push_back(path);
            return;
        }
        for(int i=idx; i<n; i++){
            if(i>idx&& candidates[i]==candidates[i-1]){
                continue;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target, i+1, sum+candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return ans;
    }
};
