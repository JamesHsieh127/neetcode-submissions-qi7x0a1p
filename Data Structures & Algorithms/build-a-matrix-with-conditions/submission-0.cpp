class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& edges){
        vector<vector<int>> graph(k);
        vector<int> indeg(k, 0);
        for(auto& a:edges){
            graph[a[0]-1].push_back(a[1]-1);
            indeg[a[1]-1]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<k; i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(int& y:graph[x]){
                indeg[y]--;
                if(indeg[y]==0){
                    q.push(y);
                }
            }
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row=topoSort(k, rowConditions);
        vector<int> col=topoSort(k, colConditions);
        if(row.size()<k|| 
        col.size()<k) return {};
        vector<int> pos(k, 0);
        for(int i=0; i<k; i++){
            pos[col[i]]=i;
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i=0; i<k; i++){
            ans[i][pos[row[i]]]=row[i]+1;
        }
        return ans;
    }
};