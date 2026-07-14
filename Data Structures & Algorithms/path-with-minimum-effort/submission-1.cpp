class Solution {
public:
    const int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    bool bfs(vector<vector<int>>& heights, int target){
        int m=heights.size(), n=heights[0].size();
        queue<pair<int, int>> q;
        q.push({0,0});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0]=true;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(x==m-1&&y==n-1) return true;
            for(auto&[dx,dy]:DIRS){
                int X=x+dx, Y=y+dy;
                if(X>=0&&X<m&&
                Y>=0&&Y<n&&
                !vis[X][Y]&&
                abs(heights[X][Y]-heights[x][y])<=target){
                    vis[X][Y]=true;
                    q.push({X, Y});
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left=-1, right=1e6+1;
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(bfs(heights, mid)){
                right=mid;
            }
            else left=mid;
        }
        return right;
    }
};