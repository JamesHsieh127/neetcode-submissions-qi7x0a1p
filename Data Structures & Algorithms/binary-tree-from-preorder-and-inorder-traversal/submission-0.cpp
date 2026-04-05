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
    vector<int> _preorder;
    unordered_map<int, int> mp;
    TreeNode* dfs(int root, int l, int r){
        if(l>r) return nullptr;
        TreeNode* node=new TreeNode(_preorder[root]);
        int idx=mp[_preorder[root]];
        node->left=dfs(root+1, l, idx-1);
        node->right=dfs(root+1+idx-l, idx+1, r);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->_preorder=preorder;
        int n=preorder.size();
        for(int i=0; i<n ;i++){
            mp[inorder[i]]=i;
        }
        return dfs(0, 0, n-1);
    }
};
