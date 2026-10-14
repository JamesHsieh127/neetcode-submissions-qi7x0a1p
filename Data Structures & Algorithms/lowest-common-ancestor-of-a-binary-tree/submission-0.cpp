/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(p==root|| q==root) return root;
        TreeNode* leftChild=lowestCommonAncestor(root->left, p, q);
        TreeNode* rightChild=lowestCommonAncestor(root->right, p, q);
        if(leftChild&& rightChild) return root;
        else if(leftChild) return leftChild;
        return rightChild;
    }
};