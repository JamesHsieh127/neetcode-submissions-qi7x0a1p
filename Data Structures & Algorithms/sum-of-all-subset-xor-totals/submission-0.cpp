class Solution {
public:
    int xorSum=0;
    void dfs(vector<int>& nums, int val, int idx){
        int n=nums.size();
        if(idx==n){
            xorSum+=val;
            return;
        }
        dfs(nums, val, idx+1);
        dfs(nums, val^=nums[idx], idx+1);
    }
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0, 0);
        return xorSum;
    }
};