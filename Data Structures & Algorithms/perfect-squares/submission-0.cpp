class Solution {
public:
    vector<vector<int>> dp;
    vector<int> path;
    vector<int> nums;
    int sum=0;
    void dfs(int n, int idx){
        if(n<sum){
            return;
        }
        if(n==sum){
            dp.push_back(path);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            sum+=nums[i];
            path.push_back(nums[i]);
            dfs(n, i);
            sum-=nums[i];
            path.pop_back();
        }
    }
    int numSquares(int n) {
        if(n<1) return 0;
        for(int i=1; i*i<=n; i++){
                nums.push_back(i*i);
        }
        dfs(n, 0);
        int ans=INT_MAX;
        for(auto& a:dp){
            ans=min(ans, (int)a.size());
        }
        return ans;
    }
};