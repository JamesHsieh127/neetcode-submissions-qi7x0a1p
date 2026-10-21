class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m=s.size(), n=p.size(), left=0;
        unordered_map<char, int> cnt;
        vector<int> ans;
        for(char& c:p) cnt[c]++;
        for(int right=0; right<m; right++){
            cnt[s[right]]--;
            while(cnt[s[right]]<0){
                cnt[s[left]]++;
                left++;
            }
            if(right-left+1==n) ans.push_back(left);
        }
        return ans;
    }
};
