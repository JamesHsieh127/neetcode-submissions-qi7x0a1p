class Solution {
public:
    vector<bool> cols, diags, antidiags;
    int ans=0;
    void dfs(int& n, int r){
        if(n==r){
            ans++;
            return;
        }
        for(int c=0; c<n; c++){
            int rc=r-c+n-1;
            if(!cols[c]&&
            !diags[r+c]&&
            !antidiags[rc]){
                cols[c]=true;
                diags[r+c]=true;
                antidiags[rc]=true;
                dfs(n, r+1);
                cols[c]=false;
                diags[r+c]=false;
                antidiags[rc]=false;
            }
        }
    }
    int totalNQueens(int n) {
        cols.assign(n, false);
        diags.assign(2*n-1, false);
        antidiags.assign(2*n-1, false);
        dfs(n, 0);
        return ans;
    }
};