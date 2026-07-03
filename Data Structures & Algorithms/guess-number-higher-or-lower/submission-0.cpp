/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left=0, right=n;
        while(left+1<right){
            int mid=left+(right-left)/2;
            int pick=guess(mid);
            if(0==pick) return mid;
            else if(1==pick) left=mid;
            else right=mid;
        }
        return right;
    }
};