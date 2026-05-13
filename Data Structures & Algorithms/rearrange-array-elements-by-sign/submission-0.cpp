class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(), i=0, j=1;
        vector<int> ans(n, 0);
        for(int& x:nums){
            if(x>0){
                ans[i]=x;
                i+=2;
            }
            else{
                ans[j]=x;
                j+=2;
            }
        }
        return ans;
    }
};