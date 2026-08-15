class Solution {
public:
    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> minHeap;
    void dfs(const string& cur){
        while(minHeap.contains(cur)&&
        minHeap[cur].size()){
            string s=minHeap[cur].top();
            minHeap[cur].pop();
            dfs(s);
        }
        ans.push_back(cur);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& a:tickets){
            minHeap[a[0]].push(a[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};