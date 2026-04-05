class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int& n, int& k, int x){
        if(path.size()==k){
            ans.push_back(path);
            return;
        }
        for(int i=x; i<=n; i++){
            path.push_back(i);
            dfs(n, k, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};