class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int left=-1, right=n-1, target=nums.back();
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target){
                right=mid;
            }
            else{
                left=mid;
            }
        }
        return nums[right];
    }
};
