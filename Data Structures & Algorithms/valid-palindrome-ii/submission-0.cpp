class Solution {
public:
    bool twoPointer(string& s, int left, int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int left=0, right=n-1;
        while(left<right){
            if(s[left]!=s[right]){
                return twoPointer(s, left+1, right)||twoPointer(s, left, right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};