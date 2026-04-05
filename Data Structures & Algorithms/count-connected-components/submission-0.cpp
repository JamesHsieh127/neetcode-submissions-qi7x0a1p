struct UnionFind{
    vector<int> parent;
    int cnt=0;
    UnionFind(int n){
        cnt=n;
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
        int pA=find(a), pB=find(b);
        if(pA!=pB){
            parent[pA]=pB;
            cnt--;
        }
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind UF(n);
        for(auto& a:edges){
            UF.unite(a[0], a[1]);
        }
        return UF.cnt;
    }
};
