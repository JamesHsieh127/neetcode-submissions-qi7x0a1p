class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    bool isPalindromic(string& s, int left, int right){
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void dfs(string& s, int idx){
        int n=s.size();
        if(idx==n){
            ans.push_back(path);
            return;
        }
        for(int i=idx; i<n; i++){
            if(isPalindromic(s, idx, i)){
                path.push_back(s.substr(idx, i-idx+1));
                dfs(s, i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(s=="") return {};
        dfs(s, 0);
        return ans;
    }
};
