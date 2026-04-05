class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(auto& a:intervals){
            if(!ans.empty()&&
            ans.back()[1]>=a[0]){
                ans.back()[1]=max(ans.back()[1], a[1]);
            }
            else{
                ans.push_back(a);
            }
        }
        return ans;
    }
};
