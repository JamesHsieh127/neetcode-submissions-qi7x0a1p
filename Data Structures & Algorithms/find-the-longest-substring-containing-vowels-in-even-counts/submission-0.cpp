class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans=0, n=s.size(), mask=0;
        vector<int> pos(1<<5, -1);
        pos[0]=0;
        for(int i=0; i<n; i++){
            if(s[i]=='a') mask^=(1<<0);
            else if(s[i]=='e') mask^=(1<<1);
            else if(s[i]=='i') mask^=(1<<2);
            else if(s[i]=='o') mask^=(1<<3);
            else if(s[i]=='u') mask^=(1<<4);
            if(~pos[mask]){
                ans=max(ans, i+1-pos[mask]);
            }
            else pos[mask]=i+1;
        }
        return ans;
    }
};