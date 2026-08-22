class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size(), left=0, ans=1;
        for(int right=1; right<n; right++){
            if(arr[right]==arr[right-1]){
                left=right;
            }
            else if(right>1&&
            !((arr[right-1]>arr[right]&& arr[right-1]>arr[right-2]) ||
            (arr[right-1]<arr[right]&& arr[right-1]<arr[right-2]))){
                left=right-1;
            }
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};