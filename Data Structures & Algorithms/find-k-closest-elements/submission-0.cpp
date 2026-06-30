class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int left=-1, right=n-k;
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(x-arr[mid]<=arr[mid+k]-x){
                right=mid;
            }
            else left=mid;
        }
        return vector<int>(arr.begin()+right, arr.begin()+right+k);
    }
};