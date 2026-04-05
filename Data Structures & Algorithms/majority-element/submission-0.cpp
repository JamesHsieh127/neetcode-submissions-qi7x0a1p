class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote=0, cnt=0, n=nums.size(), ans=0;
        for(int& x:nums){
            if(vote==0) ans=x;
            if(ans==x) vote++;
            else vote--;
        }
        for(int i=0; i<n; i++){
            if(nums[i]==ans) cnt++;
        }
        return cnt>n/2?ans:0;
    }
};