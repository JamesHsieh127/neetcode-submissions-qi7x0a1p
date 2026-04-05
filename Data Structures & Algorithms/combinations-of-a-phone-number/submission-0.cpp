class Solution {
public:
    const string MAPPING[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string path="";
    void dfs(string& s, int idx){
        int n=s.size();
        if(idx==n){
            ans.push_back(path);
            return;
        }
        for(char c:MAPPING[(s[idx]-'0')]){
            path.push_back(c);
            dfs(s, idx+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        dfs(digits, 0);
        return ans;
    }
};
