class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), ans=1;
        if(n==1) return n;
        for(int i=1; i<n; i++){
            if(nums[i-1]!=nums[i]){
                nums[ans]=nums[i];
                ans++;
            }
        }
        return ans;
    }
};