class Solution {
public:
    bool isValid(vector<int>& piles, int h, int speed){
        int sum=0;
        for(int x:piles){
            sum+=(x+speed-1)/speed;
            if(sum>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=0, right=0;
        for(int x:piles){
            right=max(right, x);
        }
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(isValid(piles, h, mid)){
                right=mid;
            }
            else{
                left=mid;
            }
        }
        return right;
    }
};
