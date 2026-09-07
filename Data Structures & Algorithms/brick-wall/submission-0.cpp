class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=0; j<wall[i].size()-1; j++){
                sum+=wall[i][j];
                mp[sum]++;
            }
        }
        int ans=n;
        for(auto&[sum, cnt]:mp){
            ans=min(ans, n-cnt);
        }
        return ans;
    }
};