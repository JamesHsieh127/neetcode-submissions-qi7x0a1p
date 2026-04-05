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
    priority_queue<int> maxHeap;
    void dfs(TreeNode* root, int k){
        if(!root) return;
        if(maxHeap.size()<k){
            maxHeap.push(root->val);
        }
        else if(root->val<maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(root->val);
        }
        dfs(root->left, k);
        dfs(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return maxHeap.top();
    }
};
