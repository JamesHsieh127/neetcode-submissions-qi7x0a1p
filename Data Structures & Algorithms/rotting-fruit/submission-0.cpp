class Solution {
public:
    int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0, fresh=0, m=grid.size(), n=grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()&& fresh){
            int len=q.size();
            ans++;
            for(int i=0; i<len; i++){
                auto[x, y]=q.front();
                q.pop();
                for(auto& [dx, dy]:DIRS){
                    int X=x+dx, Y=y+dy;
                    if(X<0||X>=m||
                    Y<0||Y>=n||
                    grid[X][Y]!=1){
                        continue;
                    }
                    grid[X][Y]=2;
                    fresh--;
                    q.push({X, Y});
                }
            }
        }
        return fresh?-1:ans;
    }
};
