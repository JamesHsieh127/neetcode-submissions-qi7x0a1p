class Solution {
public:
    int ans=0;
    int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        grid[i][j]='2';
        for(auto&[dx, dy]:DIRS){
            int x=i+dx, y=j+dy;
            if(x>=0&& x<m&&
            y>=0&& y<n&&
            grid[x][y]=='1'){
                dfs(grid, x, y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
