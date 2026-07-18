class Solution {
public:
    vector<vector<string>> res;
    void dfs(int n, int r, vector<string>& board, vector<int>& col, vector<int>& diag1, vector<int>& diag2){
        if(r==n){
            res.push_back(board);
            return;
        }
        for(int c=0; c<n; c++){
            int rc=r-c+n-1;
            if(!col[c]&&!diag1[r+c]&&!diag2[rc]){
                board[r][c]='Q';
                col[c]=1;
                diag1[r+c]=1;
                diag2[rc]=1;
                dfs(n, r+1, board, col, diag1, diag2);
                col[c]=0;
                diag1[r+c]=0;
                diag2[rc]=0;
                board[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> col(n), diag1(n*2-1), diag2(n*2-1); 
        dfs(n, 0, board, col, diag1, diag2);
        return res;
    }
};
 