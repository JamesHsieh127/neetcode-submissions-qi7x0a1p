class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        if(n<3) return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if(i&& nums[i]==nums[i-1]) continue;
            int left=i+1, right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum>0){
                    right--;
                }
                else if(sum<0){
                    left--;
                }
                else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};
