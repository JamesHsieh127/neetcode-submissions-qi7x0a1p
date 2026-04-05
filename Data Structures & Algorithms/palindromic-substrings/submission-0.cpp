class Solution {
public:
    int twoPointer(string& s, int left, int right){
        int n=s.size(), cnt=0;
        while(left>=0&& right<n&&
        s[left]==s[right]){
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n=s.size(),ans=0;
        for(int i=0; i<n; i++){
            ans+=twoPointer(s, i, i);
            ans+=twoPointer(s, i, i+1);
        }
        return ans;
    }
};
