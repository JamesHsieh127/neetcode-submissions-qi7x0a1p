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
    int dfs(TreeNode* root){
        if(!root) return 0;
        int depthL=dfs(root->left);
        int depthR=dfs(root->right);
        if(depthL==-1||
        depthR==-1||
        abs(depthL-depthR)>1){
            return -1;
        }
        return max(depthL, depthR)+1;
    }
    bool isBalanced(TreeNode* root) {
        return -1!=dfs(root);
    }
};
