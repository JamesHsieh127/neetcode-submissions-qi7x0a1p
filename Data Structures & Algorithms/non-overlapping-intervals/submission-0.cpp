class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size(), ans=0, endPoint=0;
        sort(intervals.begin(), intervals.end());
        for(int i=1; i<n; i++){
            if(intervals[endPoint][1]>intervals[i][0]){
                ans++;
                if(intervals[endPoint][1]>intervals[i][1]){
                    endPoint=i;
                }
            }
            else{
                endPoint=i;
            }
        }
        return ans;
    }
};
