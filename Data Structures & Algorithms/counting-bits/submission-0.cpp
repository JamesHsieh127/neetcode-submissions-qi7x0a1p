class Solution {
public:
    int cntOnes(int x){
        int cnt=0;
        while(x){
            if(x&1) cnt++;
            x>>=1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++){
            ans[i]=cntOnes(i);
        }
        return ans;
    }
};
