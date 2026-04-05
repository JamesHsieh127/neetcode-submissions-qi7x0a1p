class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={false};
        bool col[9][9]={false};
        bool area[3][3][9]={false};
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0'-1;
                if(row[i][x] || col[j][x] || 
                area[i/3][j/3][x]){
                    return false;
                }
                row[i][x]=true;
                col[j][x]=true;
                area[i/3][j/3][x]=true;
            }
        }
        return true;
    }
};