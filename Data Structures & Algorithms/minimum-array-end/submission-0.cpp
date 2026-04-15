class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x;
        while(n-1>0){
            ans=(ans+1)|x;
            n--;
        }
        return ans;
    }
};