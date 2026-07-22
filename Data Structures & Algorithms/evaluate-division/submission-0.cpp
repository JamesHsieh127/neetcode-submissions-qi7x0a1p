class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        int n=equations.size();
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i=0; i<n; i++){
            auto& a=equations[i];
            double& val=values[i];
            graph[a[0]].push_back({a[1], val});
            graph[a[1]].push_back({a[0], 1.0/val});
        }
        for(auto& a:queries){
            string src=a[0], des=a[1];
            if(!graph.contains(src)||!graph.contains(des)){
                ans.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> q;
            unordered_set<string> vis;
            q.push({src, 1.0});
            vis.insert(src);
            double res=-1.0;
            while(!q.empty()){
                auto[cur, val]=q.front();
                q.pop();
                if(cur==des){
                    res=val;
                    break;
                }
                for(auto&[nxt, weight]:graph[cur]){
                    if(!vis.contains(nxt)){
                        vis.insert(nxt);
                        q.push({nxt, weight*val});
                    }
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};