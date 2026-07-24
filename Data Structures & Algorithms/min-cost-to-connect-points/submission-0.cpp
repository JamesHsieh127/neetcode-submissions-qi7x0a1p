struct UnionFind{
    vector<int> parent;
    int cnt;
    UnionFind(int n){
        parent.assign(n, 0);
        cnt=n;
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    bool unite(int a, int b){
        int pa=find(a), pb=find(b);
        if(pa!=pb){
            parent[pa]=pb;
            cnt--;
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<tuple<int, int, int>> edges;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({cost, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        UnionFind uf(n);
        int ans=0, usage=0;
        for(auto& [cost, i, j]:edges){
            if(uf.unite(i, j)){
                ans+=cost;
                usage++;
                if(usage==n-1) break;
            }
        }
        return ans;
    }
};