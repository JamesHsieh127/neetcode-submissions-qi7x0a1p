class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0]<b[0];
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto& a:intervals){
            if(!minHeap.empty()&&
            minHeap.top()<a[0]){
                minHeap.pop();
            }
            minHeap.push(a[1]);
        }
        return minHeap.size();
    }
};