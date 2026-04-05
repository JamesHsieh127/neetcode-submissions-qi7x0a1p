class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
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
