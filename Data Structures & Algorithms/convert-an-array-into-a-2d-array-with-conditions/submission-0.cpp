class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int& x:nums) cnt[x]++;
        vector<vector<int>> ans;
        int n=nums.size();
        while(n>0){
            vector<int> row;
            for(auto& [x, freq]:cnt){
                if(freq>0){
                    n--;
                    freq--;
                    row.push_back(x);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};