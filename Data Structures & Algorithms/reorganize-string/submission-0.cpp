class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        string ans="";
        unordered_map<char, int> cnt;
        priority_queue<pair<int, char>> maxHeap;
        for(char& c:s){
            cnt[c]++;
        }
        for(auto&[k,v]:cnt){
            if(v>(n+1)/2) return "";
            maxHeap.push({v, k});
        }
        while(maxHeap.size()>=2){
            auto [v1, k1]=maxHeap.top();
            maxHeap.pop();
            auto [v2, k2]=maxHeap.top();
            maxHeap.pop();
            ans+=k1;
            ans+=k2;
            v1--;
            v2--;
            if(v1>0) maxHeap.push({v1, k1});
            if(v2>0) maxHeap.push({v2, k2});
        }
        if(!maxHeap.empty()) ans+=maxHeap.top().second;
        return ans;
    }
};