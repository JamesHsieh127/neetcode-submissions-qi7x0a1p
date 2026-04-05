class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0, ans=0, n=nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
            ans+=(i+1);
        }
        return ans-=sum;
    }
};