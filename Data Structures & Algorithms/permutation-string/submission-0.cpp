class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(), n=s2.size(), left=0;
        unordered_map<char, int> cnt1, cnt2;
        for(char c:s1){
            cnt1[c]++;
        }
        for(int right=0; right<n; right++){
            cnt2[s2[right]]++;
            while(right-left+1>=m){
                if(cnt1==cnt2){
                    return true;
                }
                cnt2[s2[left]]--;
                if(!cnt2[s2[left]]){
                    cnt2.erase(s2[left]);
                }
                left++;
            }
        }
        return false;
    }
};
