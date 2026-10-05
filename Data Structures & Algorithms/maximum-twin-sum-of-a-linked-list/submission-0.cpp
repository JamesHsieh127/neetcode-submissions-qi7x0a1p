/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* root){
        ListNode* slow=root;
        ListNode* fast=root;
        while(fast&& fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* root){
        ListNode* prev=nullptr;
        while(root){
            ListNode* nxt=root->next;
            root->next=prev;
            prev=root;
            root=nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* midNode=middleNode(head);
        ListNode* revList=reverseList(midNode);
        int ans=INT_MIN;
        while(revList){
            ans=max(ans, revList->val+head->val);
            revList=revList->next;
            head=head->next;
        }
        return ans;
    }
};