class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=-1, right=n;
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right= mid;
            }
            else{
                left=mid;
            }
        }
        return -1;
    }
};
