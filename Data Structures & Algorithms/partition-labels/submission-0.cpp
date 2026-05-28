class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size(), left=0, right=0;
        unordered_map<char, int> mp;
        vector<int> ans;
        for(int i=0; i<n; i++){
            mp[s[i]]=i;
        }
        for(int i=0; i<n; i++){
            right=max(right, mp[s[i]]);
            if(right==i){
                ans.push_back(right-left+1);
                left=i+1;
            }
        }
        return ans;
    }
};
