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
    vector<int> dfs(TreeNode* root, int& distance){
        if(!root) return {};
        if(!root->left && !root->right) return {1};
        vector<int> leftDis=dfs(root->left, distance);
        vector<int> rightDis=dfs(root->right, distance);
        for(int& l:leftDis){
            for(int& r:rightDis){
                if(l+r<=distance){
                    ans++;
                }
            }
        }
        vector<int> ret;
        for(int& l:leftDis){
            if(l+1<distance){
                ret.push_back(l+1);
            }
        }
        
        for(int& r:rightDis){
            if(r+1<distance){
                ret.push_back(r+1);
            }
        }
        return ret;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return ans;
    }
};
