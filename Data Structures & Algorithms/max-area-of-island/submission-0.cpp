class Solution {
public:
    int sum=0;
    int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<int>>& grid, int x, int y){
        int m=grid.size(), n=grid[0].size();
        sum++;
        grid[x][y]=-1;
        for(auto&[dx, dy]:DIRS){
            int X=x+dx, Y=y+dy;
            if(X<0||X>=m||
            Y<0||Y>=n||
            grid[X][Y]!=1){
                continue;
            }
            dfs(grid, X, Y);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), ans=0;
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    sum=0;
                    dfs(grid, i, j);
                    ans=max(ans, sum);
                }
            }
        }
        return ans;
    }
};
