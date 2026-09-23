class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size(), left=0, sum=0;
        vector<int> ans(2, 0);
        for(int right=0; right<n; right++){
            ans[grumpy[right]]+=customers[right];
            while(right-left+1>=minutes){
                sum=max(sum, ans[1]);
                if(grumpy[left]){
                    ans[1]-=customers[left];
                }
                left++;
            }
        }
        return ans[0]+sum;
    }
};