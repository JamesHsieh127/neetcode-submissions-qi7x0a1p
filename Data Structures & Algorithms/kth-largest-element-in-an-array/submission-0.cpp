class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=INT_MAX, right=INT_MIN;
        for(int x:nums){
            left=min(left, x);
            right=max(right, x);
        }
        left--;
        right++;
        while(left+1<right){
            int mid=left+(right-left)/2;
            int cnt=0;
            for(int x:nums){
                if(x>=mid) cnt++;
            }
            if(cnt>=k){
                left=mid;
            }
            else{
                right=mid;
            }
        }
        return left;
    }
};
