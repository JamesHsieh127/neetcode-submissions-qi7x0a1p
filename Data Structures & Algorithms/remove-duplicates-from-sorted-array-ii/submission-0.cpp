class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), left=0, right=0;
        while(right<n){
            int target=nums[right], cnt=0;
            while(right<n&& nums[right]==target){
                cnt++;
                if(cnt<=2){
                    nums[left]=nums[right];
                    left++;
                }
                right++;
            }
        }
        return left;
    }
};