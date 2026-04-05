class Solution {
public:
    int findMin(vector<int>& nums){
        int left=-1, right=nums.size()-1, target=nums.back();
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target){
                right=mid;
            }
            else{
                left=mid;
            }
        }
        return right;
    }
    int binarySearch(vector<int>& nums, int target, int left, int right){
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=target){
                right=mid;
            }
            else{
                left=mid;
            }
        }
        return nums[right]==target?right:-1;
    }
    int search(vector<int>& nums, int target) {
        int midIdx=findMin(nums), n=nums.size();
        if(target>nums.back()){
            return binarySearch(nums, target, -1, midIdx);
        }
        else{
            return binarySearch(nums, target, midIdx-1, n);
        }
    }
};
