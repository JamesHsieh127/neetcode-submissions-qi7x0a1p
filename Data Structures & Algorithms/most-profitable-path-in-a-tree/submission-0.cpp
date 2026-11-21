class Solution {
public:
    vector<vector<int>> graph;
    vector<int> bobTime;
    int ans=INT_MIN;
    bool dfsBob(int x, int parent, int& bob){
        if(x==bob){
            bobTime[x]=0;
            return true;
        }
        for(int& y:graph[x]){
            if(y!=parent&& dfsBob(y, x, bob)){
                bobTime[x]=bobTime[y]+1;
                return true;
            }
        }
        return false;
    }
    void dfsAlice(int x, int parent, int t, int cur, vector<int>& amount){
        if(t<bobTime[x]){
            cur+=amount[x];
        }
        else if(t==bobTime[x]){
            cur+=(amount[x]/2);
        }
        if(x!=0&& graph[x].size()==1){
            ans=max(ans, cur);
            return;
        }
        for(int& y:graph[x]){
            if(y!=parent){
                dfsAlice(y, x, t+1, cur, amount);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        this->graph.assign(n, {});
        this->bobTime.assign(n, INT_MAX);
        for(auto& e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfsBob(0, -1, bob);
        dfsAlice(0, -1, 0, 0, amount);
        return ans;
    }
};