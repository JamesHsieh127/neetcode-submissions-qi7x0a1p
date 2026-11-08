class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26,0);
        int ans=0;
        for(char& c:s){
            cnt[c-'a']++;
        }
        for(int& x:cnt){
            if(x==0) continue;
            if(x&1) ans++;
            else ans+=2;
        }
        return ans;
    }
};