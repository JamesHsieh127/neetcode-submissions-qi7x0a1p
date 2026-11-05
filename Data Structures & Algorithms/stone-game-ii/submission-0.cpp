class Solution {
public:
    vector<int> suffix;
    int dfs(int idx, int m){
        int n=suffix.size();
        if(idx+m*2>=n) return suffix[idx];
        int minVal=INT_MAX;
        for(int x=1; x<=m*2; x++){
            minVal=min(minVal, dfs(idx+x, max(m, x)));
        }
        return suffix[idx]-minVal;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        this->suffix.assign(n, 0);
        suffix.back()=piles.back();
        for(int i=n-2; i>=0; i--){
            suffix[i]=piles[i]+suffix[i+1];
        }
        return dfs(0, 1);
    }
};