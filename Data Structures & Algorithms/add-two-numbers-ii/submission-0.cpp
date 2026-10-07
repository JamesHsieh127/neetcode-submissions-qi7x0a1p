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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* revl1=reverseList(l1);
        ListNode* revl2=reverseList(l2);
        ListNode* dummy=new ListNode();
        ListNode* cur=dummy;
        int carry=0;
        while(revl1|| revl2){
            int x=0, y=0;
            if(revl1) x=revl1->val;
            if(revl2) y=revl2->val;
            int sum=x+y+carry;
            carry=sum/10;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            if(revl1) revl1=revl1->next;
            if(revl2) revl2=revl2->next;
        }
        if(carry) cur->next=new ListNode(carry);
        return reverseList(dummy->next);
    }
};