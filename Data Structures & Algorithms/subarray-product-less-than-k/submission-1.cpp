class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(), left=0, ans=0;
        long long pro=1;
        for(int right=0; right<n; right++){
            pro*=nums[right];
            while(left<=right&& pro>=k){
                pro/=nums[left];
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
};