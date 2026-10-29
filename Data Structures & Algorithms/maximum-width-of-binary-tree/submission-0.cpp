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
    vector<vector<int>> arr;
    void dfs(TreeNode* root, int depth, int idx){
        if(!root) return;
        int n=arr.size();
        if(n==depth){
            arr.push_back({idx});
        }
        else{
            arr[depth].push_back({idx});
        }
        dfs(root->left, depth+1, 2*idx);
        dfs(root->right, depth+1, 2*idx+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 1);
        int ans=0;
        for(auto& a:arr){
            int sz=a.back()-a.front()+1;
            ans=max(ans, sz);
        }
        return ans;
    }
};
