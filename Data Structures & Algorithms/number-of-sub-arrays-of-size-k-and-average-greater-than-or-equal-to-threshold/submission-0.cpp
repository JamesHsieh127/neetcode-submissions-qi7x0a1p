class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size(), left=0, ans=0, sum=0;
        for(int right=0; right<n; right++){
            sum+=arr[right];
            while(right-left+1>=k){
                if(sum>=threshold*k){
                    ans++;
                }
                sum-=arr[left];
                left++;
            }
        }
        return ans;
    }
};