class Solution {
public:
    int DIRS[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto[x, y]=q.front();
            q.pop();
            for(auto&[dx, dy]:DIRS){
                int i=x+dx, j=y+dy;
                if(i>=0&&i<m &&
                j>=0&&j<n&&
                grid[i][j]==2147483647){
                    grid[i][j]=grid[x][y]+1;
                    q.push({i, j});
                }
            }
        }
    }
};
