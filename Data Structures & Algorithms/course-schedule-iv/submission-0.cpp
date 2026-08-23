class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> graph(numCourses);
        vector<int> indeg(numCourses, 0);
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        for(auto& a:prerequisites){
            graph[a[0]].push_back(a[1]);
            indeg[a[1]]++;
            isPre[a[0]][a[1]]=true;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto& y:graph[x]){
                for(int i=0; i<numCourses; i++){
                    if(isPre[i][x]){
                        isPre[i][y]=true;
                    }
                }
                indeg[y]--;
                if(indeg[y]==0){
                    q.push(y);
                }
            }
        }
        for(auto& a:queries){
            ans.push_back(isPre[a[0]][a[1]]);
        }
        return ans;
    }
};