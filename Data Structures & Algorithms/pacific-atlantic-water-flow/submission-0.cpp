class Solution {
public:
    vector<vector<int>> ans;
    int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& heights){
        if(vis[x][y]) return;
        int m=heights.size(), n=heights[0].size(), h=heights[x][y];
        vis[x][y]=true;
        for(auto&[dx, dy]:DIRS){
            int X=x+dx, Y=y+dy;
            if(X>=0&&X<m&&
            Y>=0&&Y<n&&
            heights[X][Y]>=h){
                dfs(X, Y, vis, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        if(!m||!n) return {{}};
        vector<vector<int>> visPacific(m, vector<int>(n, 0)), visAtlantic(m, vector<int>(n, 0));
        vector<vector<int>> ans;
        for(int j=0; j<n; j++){
            dfs(0, j, visPacific, heights);
        }
        for(int i=1; i<m; i++){
            dfs(i, 0, visPacific, heights);
        }
        for(int j=0; j<n; j++){
            dfs(m-1, j, visAtlantic, heights);
        }
        for(int i=0; i<m-1; i++){
            dfs(i, n-1, visAtlantic, heights);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visPacific[i][j]&&visAtlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
