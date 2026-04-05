class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;
    void dfs(int x){
        vis[x]=true;
        for(auto& y:graph[x]){
            if(!vis[y]){
                dfs(y);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n-1!=edges.size()) return false;
        this->graph.resize(n);    
        this->vis.resize(n, false);
        for(auto& a:edges){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        dfs(0);
        for(bool b:vis){
            if(!b) return false;
        }
        return true;
    }
};
