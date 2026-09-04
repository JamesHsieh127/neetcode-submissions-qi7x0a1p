class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        int n=order.size();
        vector<int> mp(26, 0);
        for(int i=0; i<n; i++){
            mp[order[i]-'a']=i+1;
        }
        sort(s.begin(), s.end(), [&](char a, char b){
            return mp[a-'a']<mp[b-'a'];
        });
        return s;
    }
};