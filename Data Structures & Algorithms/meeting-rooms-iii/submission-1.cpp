class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> minHeapIdle;
        for(int i=0; i<n; i++){
            minHeapIdle.push(i);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeapUse;
        vector<int> cnt(n, 0);
        for(auto& a:meetings){
            long long start=a[0], end=a[1];
            while(!minHeapUse.empty()&&
            minHeapUse.top().first<=start){
                minHeapIdle.push(minHeapUse.top().second);
                minHeapUse.pop();
            }
            int x=0;
            if(!minHeapIdle.empty()){
                x=minHeapIdle.top();
                minHeapIdle.pop();
            }
            else{
                auto[fin, room]=minHeapUse.top();
                x=room;
                minHeapUse.pop();
                end+=(fin-start);
            }
            minHeapUse.push({end, x});
            cnt[x]++;
        }
        int maxVal=INT_MIN, ans=0;
        for(int i=0; i<n; i++){
            if(cnt[i]>maxVal){
                ans=i;
                maxVal=cnt[i];
            }
        }
        return ans;
    }
};