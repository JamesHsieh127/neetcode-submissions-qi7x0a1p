class Solution {
public:
    bool check(vector<int>& nums, int maxVal, int p){
        int cnt=0, n=nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i+1]-nums[i]<=maxVal){
                cnt++;
                i++;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left=-1, right=nums.back()-nums[0];
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(check(nums, mid, p)){
                right=mid;
            }
            else left=mid;
        }
        return right;
    }
};