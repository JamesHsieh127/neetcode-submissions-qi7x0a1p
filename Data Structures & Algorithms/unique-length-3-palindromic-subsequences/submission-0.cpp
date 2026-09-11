class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        for(char c='a'; c<='z'; c++){
            if(!s.contains(c)) continue;
            int left=s.find(c), right=s.rfind(c);
            vector<bool> vis(26, false);
            for(int i=left+1; i<right; i++){
                if(!vis[s[i]-'a']){
                    vis[s[i]-'a']=true;
                    ans++;
                }
            }
        }
        return ans;
    }
};