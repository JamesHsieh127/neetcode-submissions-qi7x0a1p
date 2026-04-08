class Solution {
public:
    int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<char>>& board, int x, int y){
        int m=board.size(), n=board[0].size();
        if(x<0||x>=m||
        y<0||y>=n||
        board[x][y]!='O'){
            return;
        }
        board[x][y]='A';
        for(auto& [dx, dy]:DIRS){
            int X=x+dx, Y=y+dy;
            dfs(board, X, Y);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++){
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        for(int j=0; j<n; j++){
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='A'){
                    board[i][j]='O';
                }
            }
        }
    }
};
