class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=left;
        for(int x=left+1; x<=right; x++){
            ans&=x;
        }
        return ans;
    }
};