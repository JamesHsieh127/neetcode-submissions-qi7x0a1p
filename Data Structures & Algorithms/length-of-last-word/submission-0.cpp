class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(), ans=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]!=' ') ans++;
            if(ans!=0&& s[i]==' ') break;
        }
        return ans;
    }
};