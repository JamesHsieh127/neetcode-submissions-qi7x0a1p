class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& a:times){
            adj[a[0]].push_back({a[1], a[2]});
        }
        vector<int> dis(n+1, INT_MAX);
        dis[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});
        while(!minHeap.empty()){
            auto[du, u]=minHeap.top();
            minHeap.pop();
            if(du>dis[u]) continue;
            for(auto& [v, w]:adj[u]){
                int newDis=du+w;
                if(newDis<dis[v]){
                    dis[v]=newDis;
                    minHeap.push({newDis, v});
                }
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            if(dis[i]==INT_MAX) return -1;
            ans=max(ans, dis[i]);
        }
        return ans;
    }
};