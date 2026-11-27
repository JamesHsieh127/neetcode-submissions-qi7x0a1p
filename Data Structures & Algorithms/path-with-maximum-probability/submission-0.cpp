class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m=edges.size();
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0; i<m; i++){
            int u=edges[i][0], v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        priority_queue<pair<double, int>> maxHeap;
        vector<double> dp(n, 0);
        dp[start_node]=1.0;
        maxHeap.push({1.0, start_node});
        while(!maxHeap.empty()){
            auto [xProb, x]=maxHeap.top();
            maxHeap.pop();
            for(auto& [y, yProb]:adj[x]){
                if(dp[y]<xProb*yProb){
                    dp[y]=xProb*yProb;
                    maxHeap.push({dp[y], y});
                }
            }
        }
        return dp[end_node];
    }
};