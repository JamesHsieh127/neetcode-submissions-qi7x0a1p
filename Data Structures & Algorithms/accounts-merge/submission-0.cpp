class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<int>> mp;
    unordered_set<string> st;
    vector<bool> vis;
    vector<string> path;
    void dfs(vector<vector<string>>& accounts, int idx){
        vis[idx]=true;
        for(int j=1; j<accounts[idx].size(); j++){
            string s=accounts[idx][j];
            if(st.contains(s)) continue;
            st.insert(s);
            path.push_back(s);
            for(int& x:mp[s]){
                if(!vis[x]){
                    dfs(accounts, x);
                }
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                mp[accounts[i][j]].push_back(i);
            }
        }
        vis.assign(n, false);
        for(int i=0; i<n; i++){
            if(vis[i]) continue;
            st.clear();
            path.clear();
            dfs(accounts, i);
            sort(path.begin(), path.end());
            vector<string> res;
            res.push_back(accounts[i][0]);
            for(string& s:path){
                res.push_back(s);
            }
            ans.push_back(res);
        }
        return ans;
    }
};