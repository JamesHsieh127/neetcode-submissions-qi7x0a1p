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
    int dfs(TreeNode* root){
        if(!root) return 0;
        int depthL=dfs(root->left);
        int depthR=dfs(root->right);
        ans=max(ans, depthL+depthR);
        return max(depthL, depthR)+1;
    } 
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
