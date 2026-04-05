class Solution {
public:
    vector<vector<int>> graph;
    vector<int> colors;
    bool dfs(int& x){
        colors[x]=1;
        for(int& y:graph[x]){
            if(colors[y]==1||
            (colors[y]==0&& dfs(y))){
                return true;
            }
        }
        colors[x]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        this->graph=vector<vector<int>>(numCourses);
        this->colors=vector<int>(numCourses, 0);
        for(auto& a:prerequisites){
            graph[a[1]].push_back(a[0]);
        }
        for(int i=0; i<numCourses; i++){
            if(!colors[i]&& dfs(i)){
                return false;
            }
        }
        return true;
    }
};
