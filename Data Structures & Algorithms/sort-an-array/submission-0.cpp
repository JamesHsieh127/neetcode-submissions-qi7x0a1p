class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right){
        if(left<right){
            int mid=left+(right-left)/2;
            int pivot=nums[mid], i=left, j=right;
            while(i<=j){
                while(nums[i]<pivot) i++;
                while(nums[j]>pivot) j--;
                if(i<=j){
                    if(i!=j){
                        nums[i]^=nums[j];
                        nums[j]^=nums[i];
                        nums[i]^=nums[j];
                    }
                    i++;
                    j--;
                }
            }
            if(left<j) quickSort(nums, left, j);
            if(i<right) quickSort(nums, i, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        quickSort(nums, left, right);
        return nums;
    }
};