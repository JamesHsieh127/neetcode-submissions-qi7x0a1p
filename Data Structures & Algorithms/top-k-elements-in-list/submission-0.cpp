class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        priority_queue<pair<int, int>> maxHeap;
        vector<int> ans;
        for(int x:nums){
            cnt[x]++;
        }
        for(auto& [key, val]:cnt){
            maxHeap.push({val, key});
        }
        while(k){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }
        return ans;
    }
};