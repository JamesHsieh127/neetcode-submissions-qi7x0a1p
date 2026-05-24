class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i=0; i<n; i++){
            adj[i]=vector<pair<int, int>>();
        }
        for(auto& a:edges){
            int s=a[0], d=a[1], w=a[2];
            adj[s].push_back({d, w});
        }
        unordered_map<int, int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});
        while(!minHeap.empty()){
            auto[w1, n1]=minHeap.top();
            minHeap.pop();
            if(ans.contains(n1)) continue;
            ans[n1]=w1;
            for(auto& [n2, w2]:adj[n1]){
                if(!ans.contains(n2)){
                    minHeap.push({w1+w2, n2});
                }
            }
        }
        for(int i=0; i<n; i++){
            if(!ans.contains(i)) ans[i]=-1;
        }
        return ans;
    }
};
