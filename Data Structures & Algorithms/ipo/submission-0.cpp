class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size(), cur=0;
        vector<pair<int, int>> arr;
        priority_queue<int> maxHeap;
        for(int i=0; i<n; i++){
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<k; i++){
            while(cur<n && arr[cur].first<=w){
                maxHeap.push(arr[cur].second);
                cur++;
            }
            if(!maxHeap.empty()){
                w+=maxHeap.top();
                maxHeap.pop();
            }
            else{
                break;
            }
        }
        return w;
    }
};