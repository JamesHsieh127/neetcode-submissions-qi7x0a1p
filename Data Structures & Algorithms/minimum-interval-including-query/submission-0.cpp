class Solution {
public:
    static bool compare(vector<int>&a, vector<int>& b){
        return a[0]<b[0];
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=queries.size();
        vector<int> qIdx(n, 0);
        for(int i=0; i<n; i++){
            qIdx[i]=i;
        }
        sort(qIdx.begin(), qIdx.end(),
            [&](int a, int b) {
                return queries[a] < queries[b];
            });
        sort(intervals.begin(), intervals.end(), compare);
        priority_queue<vector<int>> maxHeap;
        vector<int> ans(n, -1);
        int i=0;
        for(auto& qi:qIdx){
            while(i<intervals.size()&& intervals[i][0]<=queries[qi]){
                int l=intervals[i][1]-intervals[i][0]+1;
                maxHeap.push({-l, intervals[i][0], intervals[i][1]});
                i++;
            }
            while(!maxHeap.empty() && maxHeap.top()[2]<queries[qi]){
                maxHeap.pop();
            }
            if(!maxHeap.empty()){
                ans[qi]=-maxHeap.top()[0];
            }
        }
        return ans;
    }
};