class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), left=0, res=INT_MAX, match=0, start=0;
        unordered_map<char, int> need, mp;
        for(char c:t) need[c]++;
        for(int right=0; right<n; right++){
            mp[s[right]]++;
            if(need.contains(s[right]) && need[s[right]]==mp[s[right]]){
                match++;
            }
            while(match==need.size()){
                if(right-left+1<res){
                    res=right-left+1;
                    start=left;
                }
                if(need.contains(s[left]) && need[s[left]]==mp[s[left]]){
                    match--;
                }
                mp[s[left]]--;
                left++;
            }
        }
        return res==INT_MAX?"":s.substr(start, res);
    }
};