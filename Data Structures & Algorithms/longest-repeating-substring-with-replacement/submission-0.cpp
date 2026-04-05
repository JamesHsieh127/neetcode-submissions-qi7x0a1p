class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), left=0, ans=0, maxWindow=0;
        unordered_map<char, int> cnt;
        for(int right=0; right<n; right++){
            cnt[s[right]]++;
            maxWindow=max(maxWindow, cnt[s[right]]);
            while(right-left+1-maxWindow>k){
                cnt[s[left]]--;
                left++;
            }
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};
