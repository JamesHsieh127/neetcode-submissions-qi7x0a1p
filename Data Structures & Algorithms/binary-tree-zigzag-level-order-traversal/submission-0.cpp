/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int depth){
        if(!root) return;
        int n=ans.size();
        if(n==depth){
            ans.push_back({root->val});
        }
        else ans[depth].push_back(root->val);
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);
        for(int i=0; i<ans.size(); i++){
            if(i&1) reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};