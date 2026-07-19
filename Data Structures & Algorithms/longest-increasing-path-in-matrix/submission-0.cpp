class Solution {
public:
    const int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int x, int y){
        int m=matrix.size(), n=matrix[0].size();
        if(dp[x][y]) return dp[x][y];
        dp[x][y]++;
        for(auto& [dx, dy]:DIRS){
            int X=x+dx, Y=y+dy;
            if(X>=0&&X<m&&
            Y>=0&&Y<n&&
            matrix[X][Y]>matrix[x][y]){
                dp[x][y]=max(dp[x][y], dfs(matrix, X, Y)+1);
            }
        }
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), ans=INT_MIN;
        dp.assign(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans=max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};
