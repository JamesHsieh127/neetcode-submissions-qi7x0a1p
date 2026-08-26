class Solution {
public:
    const int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    bool check(vector<vector<int>>& grid, int threshold){
        if(grid[0][0]>threshold) return false;
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0]=true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()){
            auto[x, y]=q.front();
            q.pop();
            for(auto&[dx, dy]:DIRS){
                int X=x+dx, Y=y+dy;
                if(X>=0&&X<m&&
                Y>=0&&Y<n&&
                grid[X][Y]<=threshold){
                    if(!vis[X][Y]){
                        q.push({X,Y});
                        vis[X][Y]=true;
                    }
                }
            }
        }
        return vis[m-1][n-1];
    }
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int left=-1, right=m*n;
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(check(grid, mid)){
                right=mid;
            }
            else left=mid;
        }
        return right;
    }
};
