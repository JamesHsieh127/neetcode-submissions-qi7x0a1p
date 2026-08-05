class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0, right=1;
        for(int& x:weights){
            left=max(left, x);
            right+=x;
        }
        left--;
        while(left+1<right){
            int mid=left+(right-left)/2;
            int day=1, sum=0;
            for(int& x:weights){
                if(sum+x>mid){
                    day++;
                    sum=x;
                }
                else sum+=x;
            }
            if(day<=days){
                right=mid;
            }
            else left=mid;
        }
        return right;
    }
};