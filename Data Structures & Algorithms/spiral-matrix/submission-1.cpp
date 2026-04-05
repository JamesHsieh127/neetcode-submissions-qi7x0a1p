class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int up=0, down=matrix.size()-1;
        int left=0, right=matrix[0].size()-1;
        vector<int> ans;
        while(true){
            for(int j=left; j<=right; j++){
                ans.push_back(matrix[up][j]);
            }
            up++;
            if(up>down) break;
            for(int i=up; i<=down; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(left>right) break;
            for(int j=right; j>=left; j--){
                ans.push_back(matrix[down][j]);
            }
            down--;
            if(up>down) break;
            for(int i=down; i>=up; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            if(left>right) break;
        }
        return ans;
    }
};
