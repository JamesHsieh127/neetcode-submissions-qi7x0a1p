class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int> sortNums=nums;
        sort(sortNums.begin(), sortNums.end());
        int left=(n-1)/2, right=n-1;
        for(int i=0; i<n; i++){
            if(i&1){
                nums[i]=sortNums[right];
                right--;
            }
            else{
                nums[i]=sortNums[left];
                left--;
            }
        }
    }
};
