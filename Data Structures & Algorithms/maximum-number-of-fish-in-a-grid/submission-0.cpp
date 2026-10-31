class Solution {
public:
    int ans=0, sum=0;
    const int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<int>>& grid, int x, int y){
        int m=grid.size(), n=grid[0].size();
        if(x<0||x>=m||
        y<0||y>=n||
        grid[x][y]==0) return;
        sum+=grid[x][y];
        grid[x][y]=0;
        for(auto&[dx, dy]:DIRS){
            int X=x+dx, Y=y+dy;
            dfs(grid, X, Y);
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                sum=0;
                dfs(grid, i, j);
                ans=max(ans, sum);
            }
        }
        return ans;
    }
};
