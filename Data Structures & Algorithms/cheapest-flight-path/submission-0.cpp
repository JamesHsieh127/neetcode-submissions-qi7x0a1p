class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& a:flights){
            adj[a[0]].push_back({a[1], a[2]});
        }
        vector<int> ans(n, INT_MAX);
        ans[src]=0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        int cnt=0;
        while(!q.empty()&& cnt<=k){
            int sz=q.size();
            while(sz){
                auto [cur, cost]=q.front();
                q.pop();
                for(auto& nxt:adj[cur]){
                    if(cost+nxt.second<ans[nxt.first]){
                        ans[nxt.first]=cost+nxt.second;
                        q.push({nxt.first, cost+nxt.second});
                    }
                }
                sz--;
            }
            cnt++;
        }
        if(ans[dst]==INT_MAX) return -1;
        return ans[dst];
    }
};
