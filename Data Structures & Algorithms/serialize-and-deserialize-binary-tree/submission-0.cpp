/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "#";
        }
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(!cur){
                ans+="#,";
                continue;
            }
            ans+=to_string(cur->val)+",";
            q.push(cur->left);
            q.push(cur->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#") return nullptr;
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        TreeNode* root=new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            getline(ss, item, ',');
            if(item!="#"){
                cur->left=new TreeNode(stoi(item));
                q.push(cur->left);
            }
            getline(ss, item, ',');
            if(item!="#"){
                cur->right=new TreeNode(stoi(item));
                q.push(cur->right);
            }
        }
        return root;
    }
};