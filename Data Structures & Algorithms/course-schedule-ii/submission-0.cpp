class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indeg(numCourses, 0);
        vector<int> ans;
        for(auto& a:prerequisites){
            graph[a[1]].push_back(a[0]);
            indeg[a[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto& nxt:graph[x]){
                indeg[nxt]--;
                if(indeg[nxt]==0){
                    q.push(nxt);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};
