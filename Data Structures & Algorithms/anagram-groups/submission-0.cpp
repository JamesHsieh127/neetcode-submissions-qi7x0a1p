class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(string& s:strs){
            string sortedS=s;
            sort(sortedS.begin(), sortedS.end());
            mp[sortedS].push_back(s);
        }
        for(auto& [key, val]:mp){
            ans.push_back(val);
        }
        return ans;
    }
};
