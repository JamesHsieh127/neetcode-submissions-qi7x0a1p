class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<pair<int, pair<int, int>>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({tasks[i][0], {tasks[i][1], i}});
        }
        sort(arr.begin(), arr.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> minHeap;
        vector<int> ans;
        long long curTime=0;
        int i=0;
        while(ans.size()<n){
            if(minHeap.empty()&& curTime<arr[i].first){
                curTime=arr[i].first;
            }
            while(i<n&& arr[i].first<=curTime){
                minHeap.push({arr[i].second.first, arr[i].second.second});
                i++;
            }
            auto [procTime, idx]=minHeap.top();
            minHeap.pop();
            ans.push_back(idx);
            curTime+=procTime;
        }
        return ans;
    }
};