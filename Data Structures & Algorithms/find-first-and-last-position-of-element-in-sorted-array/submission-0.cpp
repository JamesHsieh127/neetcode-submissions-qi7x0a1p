class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right){
        int n=nums.size();
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target) left=mid;
            else right=mid;
        }
        return right;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n=nums.size();
        ans[0]=binarySearch(nums, target, -1, n);
        if(ans[0]==n|| nums[ans[0]]!=target) return {-1, -1};
        ans[1]=binarySearch(nums, target+1, -1, n)-1;
        return ans;
    }
};