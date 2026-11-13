class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size(), third=INT_MIN;
        if(n<3) return false;
        stack<int> stk;
        for(int i=n-1; i>=0; i--){
            if(nums[i]<third) return true;
            while(!stk.empty()&& nums[i]>stk.top()){
                third=stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};