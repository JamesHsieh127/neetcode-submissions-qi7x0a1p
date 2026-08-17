class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0), ans;
        for(auto& a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
            indeg[a[0]]++;
            indeg[a[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i]==1) q.push(i);
        }
        while(n>2){
            int sz=q.size();
            n-=sz;
            for(int i=0; i<sz; i++){
                int x=q.front();
                q.pop();
                for(auto& y:adj[x]){
                    indeg[y]--;
                    if(indeg[y]==1) q.push(y);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};