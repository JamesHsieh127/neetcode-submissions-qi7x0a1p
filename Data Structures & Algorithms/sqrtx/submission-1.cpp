class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int left=0, right=x;
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(mid>(x/mid)) right=mid;
            else left=mid;
        }
        return left;
    }
};