class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(), n=boxGrid[0].size();
        if(!m||!n) return boxGrid;
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for(int i=0; i<m; i++){
            int cur=n-1;
            for(int j=n-1; j>=0; j--){
                if(boxGrid[i][j]=='*'){
                    ans[j][m-1-i]='*';
                    cur=j-1;
                }
                else if(boxGrid[i][j]=='#'){
                    ans[cur][m-1-i]='#';
                    cur--;
                }
            }
        }
        return ans;
    }
};