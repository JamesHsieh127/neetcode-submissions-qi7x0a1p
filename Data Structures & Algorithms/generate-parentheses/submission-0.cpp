class Solution {
public:
    vector<string> ans;
    string path;
    void dfs(int& n, int left, int right){
        if(path.size()==2*n){
            ans.push_back(path);
            return;
        }
        if(left<n){
            path.push_back('(');
            dfs(n, left+1, right);
            path.pop_back();
        }
        if(left>right){
            path.push_back(')');
            dfs(n, left, right+1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return ans;
    }
};
