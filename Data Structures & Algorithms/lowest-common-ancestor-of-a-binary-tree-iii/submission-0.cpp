/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if(!p) return q;
        if(!q) return p;
        Node* a=p;
        Node* b=q;
        while(a!=b){
            if(a->parent){
                a=a->parent;
            }
            else a=q;
            if(b->parent){
                b=b->parent;
            }
            else b=p;
        }
        return a;
    }
};