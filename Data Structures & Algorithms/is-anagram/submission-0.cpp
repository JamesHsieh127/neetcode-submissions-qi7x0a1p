class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0), ans(26, 0);
        for(char c:s){
            cnt[c-'a']++;
        }
        for(char c:t){
            cnt[c-'a']--;
        }
        return cnt==ans;
    }
};
