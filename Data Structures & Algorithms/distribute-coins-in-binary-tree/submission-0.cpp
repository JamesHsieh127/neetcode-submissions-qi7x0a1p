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
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0,0};
        auto[coinL, nodeL]=dfs(root->left);
        auto[coinR, nodeR]=dfs(root->right);
        int coins=coinL+coinR+root->val;
        int nodes=nodeL+nodeR+1;
        ans+=abs(coins-nodes);
        return {coins, nodes};
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
