class Solution {
public:
    const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& a:roads){
            adj[a[0]].push_back({a[1], a[2]});
            adj[a[1]].push_back({a[0], a[2]});
        }
        vector<long long> dis(n, LLONG_MAX);
        vector<int> cnt(n,0);
        dis[0]=0;
        cnt[0]=1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;
        minHeap.push({0,0});
        while(!minHeap.empty()){
            auto [dx,x]=minHeap.top();
            minHeap.pop();
            if(x==n-1) return cnt.back();
            if(dx>dis[x]) continue;
            for(auto& [y, d]:adj[x]){
                long long nxtDis=dx+d;
                if(nxtDis<dis[y]){
                    dis[y]=nxtDis;
                    cnt[y]=cnt[x];
                    minHeap.push({nxtDis,y});
                }
                else if(nxtDis==dis[y]){
                    cnt[y]=(cnt[y]+cnt[x])%MOD;
                }
            }
        }
        return cnt.back();
    }
};