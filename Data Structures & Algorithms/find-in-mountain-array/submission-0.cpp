/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray& mountainArr, int left, int right, int target, bool isAscending){
        while(left+1<right){
            int mid=left+(right-left)/2, val=mountainArr.get(mid);
            if(val==target) return mid;
            if(isAscending){
                if(val>=target) right=mid;
                else left=mid;
            }
            else{
                if(val<=target) right=mid;
                else left=mid;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int left=-1, right=n-1;
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1)){
                right=mid;
            }
            else left=mid;
        }
        int peak=right;
        int ans=binarySearch(mountainArr, -1, peak+1, target, true);
        if(ans!=-1) return ans;
        return binarySearch(mountainArr, peak, n, target, false);
    }
};