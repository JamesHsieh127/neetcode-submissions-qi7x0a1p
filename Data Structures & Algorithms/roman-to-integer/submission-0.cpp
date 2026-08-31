class Solution {
public:
    unordered_map<char, int> mp={
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        int ans=0, n=s.size();
        for(int i=0; i<n; i++){
            int x=mp[s[i]];
            if(i<n-1&&
            x<mp[s[i+1]]){
                ans-=x;
            }
            else ans+=x;
        }
        return ans;
    }
};