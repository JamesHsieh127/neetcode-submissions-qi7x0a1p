class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(), maxPos=0, curPos=0, ans=0;
        for(int i=0; i<n-1; i++){
            maxPos=max(maxPos, i+nums[i]);
            if(i==curPos){
                curPos=maxPos;
                ans++;
            }
        }
        return ans;
    }
};