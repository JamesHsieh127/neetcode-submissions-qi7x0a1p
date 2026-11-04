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
    unordered_map<int,vector<TreeNode*>> mp; 
    void dfs(int& x){
        if(mp.contains(x)){
            return;
        }
        if(x==1){
            mp[1].push_back(new TreeNode(0));
        }
        else{
            for(int i=1; i<x; i+=2){
                int left=i, right=x-i-1;
                dfs(left);
                dfs(right);
                for(auto leftNode:mp[left]){
                    for(auto rightNode:mp[right]){
                        TreeNode* root=new TreeNode(0, leftNode, rightNode);
                        mp[x].push_back(root);
                    }
                }
            }
        }
        return;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        dfs(n);
        return mp[n];
    }
};