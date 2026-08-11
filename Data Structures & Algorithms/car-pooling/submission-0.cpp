class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> mp(1001, 0);
        int sum=0;
        for(auto& a:trips){
            int ppl=a[0], from=a[1], to=a[2];
            mp[from]+=ppl;
            mp[to]-=ppl;
        }
        for(int& x:mp){
            sum+=x;
            if(sum>capacity) return false;
        }
        return true;
    }
};