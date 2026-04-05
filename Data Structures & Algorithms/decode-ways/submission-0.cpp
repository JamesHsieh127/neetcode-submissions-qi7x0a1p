class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1, 0);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            int x=s[i-1]-'0';
            if(1<=x&& x<=9){
                dp[i]+=dp[i-1];
            }
            if(i>1){
                int y=(s[i-2]-'0')*10+(s[i-1]-'0');
                if(10<=y&& y<=26){
                    dp[i]+=dp[i-2];
                }
            }
        }
        return dp.back();
    }
};