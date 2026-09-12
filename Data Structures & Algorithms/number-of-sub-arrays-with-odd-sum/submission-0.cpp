class Solution {
public:
    const int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size(), ans=0;
        vector<int> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1]=prefix[i]+arr[i];
        }
        unordered_map<int, int> mp;
        for(int i=0; i<=n; i++){
            ans=(ans+mp[1-prefix[i]&1])%MOD;
            mp[prefix[i]&1]++;
        }
        return ans;
    }
};