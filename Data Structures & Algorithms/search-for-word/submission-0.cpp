class Solution {
public:
    int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        int m=board.size(), n=board[0].size();
        if(board[i][j]!=word[k]){
            return false;
        }
        if(k+1==word.size()){
            return true;
        }
        board[i][j]='0';
        for(auto&[dx, dy]:DIRS){
            if(i+dx>=0&& i+dx<m&&
            j+dy>=0&& j+dy<n&&
            dfs(board, word, i+dx, j+dy, k+1)){
                return true;
            }
        }
        board[i][j]=word[k];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
