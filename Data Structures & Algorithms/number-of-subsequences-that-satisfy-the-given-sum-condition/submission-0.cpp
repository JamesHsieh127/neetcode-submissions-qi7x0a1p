class Solution {
public:
    const int MOD=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), ans=0;
        int left=0, right=n-1;
        vector<int> pows(n,1);
        for(int i=1; i<n; i++){
            pows[i]=(pows[i-1]*2)%MOD;
        }
        while(left<=right){
            int sum=nums[left]+nums[right];
            if(sum>target) right--;
            else{
                ans=(ans+pows[right-left])%MOD;
                left++;
            }
        }
        return ans;
    }
};