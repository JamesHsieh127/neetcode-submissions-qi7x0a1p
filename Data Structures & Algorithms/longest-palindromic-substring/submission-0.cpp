class Solution {
public:
    void twoPointer(string& s, int left, int right, int& start, int& end){
        int n=s.size();
        while(left>=0&&
        right<=n&&
        left<=right &&
        s[left]==s[right]){
            left--;
            right++;
        }
        if(right-left-1>=end){
            end=right-left-1;
            start=left+1;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size(), start=0, end=1;
        if(n<2) return s;
        for(int i=0; i<n; i++){
            twoPointer(s, i, i, start, end);
            twoPointer(s, i, i+1, start, end);
        }
        return s.substr(start, end);
    }
};
