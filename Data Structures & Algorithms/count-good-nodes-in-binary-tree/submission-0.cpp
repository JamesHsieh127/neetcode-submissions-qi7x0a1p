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
    int ans=0;
    int maxVal=INT_MIN;
    void dfs(TreeNode* root){
        if(!root) return;
        if(root->val>=maxVal){
            ans++;
            maxVal=root->val;
        }
        dfs(root->left);
        dfs(root->right);
    }
    int goodNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
