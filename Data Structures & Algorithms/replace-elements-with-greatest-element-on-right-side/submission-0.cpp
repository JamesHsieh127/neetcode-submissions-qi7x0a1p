class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size(), maxVal=arr.back();
        vector<int> ans(n, -1);
        for(int i=n-2; i>=0; i--){
            maxVal=max(maxVal, arr[i+1]);
            ans[i]=maxVal;
        }
        return ans;
    }
};