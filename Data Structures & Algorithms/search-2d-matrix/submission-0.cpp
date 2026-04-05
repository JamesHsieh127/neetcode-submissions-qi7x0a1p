class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int left=-1, right=n;
        for(int i=0; i<m; i++){
            if(matrix[i].back()<target){
                continue;
            }
            if(matrix[i][0]>target){
                break;
            }
            while(left+1<right){
                int mid=left+(right-left)/2;
                if(matrix[i][mid]==target) return true;
                else if(matrix[i][mid]>target) right=mid;
                else left=mid;
            }
        }
        return false;
    }
};
