class Solution {
public:
    bool check(vector<int>& nums, int mid, int k){
        int cnt=1, sum=0;
        for(int& x:nums){
            if(sum+x<=mid){
                sum+=x;
                continue;
            }
            if(cnt==k) return false;
            cnt++;
            sum=x;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int left=INT_MIN, right=0;
        for(int& x:nums){
            left=max(left, x);
            right+=x;
        }
        left--;
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(check(nums, mid, k)) right=mid;
            else left=mid;
        }
        return right;
    }
};