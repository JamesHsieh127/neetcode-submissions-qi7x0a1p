struct UnionFind{
    vector<int> parent;
    UnionFind(int n){
        for(int i=0; i<n; i++){
            parent.push_back(i);
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int a, int b){
        int pa=find(a), pb=find(b);
        if(pa!=pb){
            parent[pa]=pb;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        UnionFind uf(n+1);
        for(auto& a:edges){
            int x=uf.find(a[0]), y=uf.find(a[1]);
            if(x==y) return a;
            uf.unite(x, y);
        }
        return {};
    }
};
