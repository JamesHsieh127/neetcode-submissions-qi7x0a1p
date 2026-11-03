class Solution {
public:
    const int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<pair<int,int>> adj;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=-1;
                    while(!q.empty()){
                        auto[x,y]=q.front();
                        q.pop();
                        adj.push_back({x,y});
                        for(auto&[dx,dy]:DIRS){
                            int X=x+dx,Y=y+dy;
                            if(X<0||X>=m||
                            Y<0||Y>=n||
                            grid[X][Y]!=1) continue;
                            q.push({X,Y});
                            grid[X][Y]=-1;
                        }
                    }
                    for(auto& a:adj){
                        q.push({a.first, a.second});
                    }
                    int ans=0;
                    while(!q.empty()){
                        int sz=q.size();
                        for(int i=0; i<sz; i++){
                            auto[x,y]=q.front();
                            q.pop();
                            for(auto&[dx,dy]:DIRS){
                                int X=x+dx,Y=y+dy;
                                if(X<0||X>=m||
                                Y<0||Y>=n||
                                grid[X][Y]==-1) continue;
                                if(grid[X][Y]==1){
                                    return ans;
                                }
                                q.push({X,Y});
                                grid[X][Y]=-1;
                            }
                        }
                        ans++;
                    }
                }
            }
        }
        return 0;
    }
};