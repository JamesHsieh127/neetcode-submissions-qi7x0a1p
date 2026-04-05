class Solution {
public:
    int target=0;
    bool dfs(vector<int>& nums, int idx, int sum){
        if(sum==target){
            return true;
        }
        if(sum>target||idx==nums.size()){
            return false;
        }
        if(dfs(nums, idx+1, sum)||
        dfs(nums, idx+1, sum+nums[idx])){
            return true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int ans=0, maxVal=0, n=nums.size();
        for(int& x:nums) maxVal+=x;
        if(maxVal&1) return false;
        target=maxVal/2;
        return dfs(nums, 0, 0);
    }
};
