class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(), left=0, ans=INT_MIN;
        unordered_map<char, int> cnt;
        for(int right=0; right<n; right++){
            cnt[s[right]]++;
            while(cnt[s[right]]>1){
                cnt[s[left]]--;
                left++;
            }
            ans=max(ans, right-left+1);
        }
        return ans==INT_MIN?0:ans;
    }
};
