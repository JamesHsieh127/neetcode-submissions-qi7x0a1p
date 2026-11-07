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
    vector<TreeNode*> ans;
    unordered_set<int> st;
    TreeNode* dfs(TreeNode* root){
        if(!root) return nullptr;
        root->left=dfs(root->left);
        root->right=dfs(root->right);
        if(!st.contains(root->val)){
            return root;
        }
        if(root->left) ans.push_back(root->left);
        if(root->right) ans.push_back(root->right);
        return nullptr;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return ans;
        for(int& x:to_delete) st.insert(x);
        if(dfs(root)){
            ans.push_back(root);
        }
        return ans;
    }
};