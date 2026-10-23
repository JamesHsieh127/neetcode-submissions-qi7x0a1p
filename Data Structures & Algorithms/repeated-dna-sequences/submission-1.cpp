class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        vector<string> ans;
        if(n<10) return ans;
        unordered_map<string, int> cnt;
        for(int i=0; i<=n-10; i++){
            string subS=s.substr(i, 10);
            cnt[subS]++;
            if(cnt[subS]==2){
                ans.push_back(subS);
            }
        }
        return ans;
    }
};