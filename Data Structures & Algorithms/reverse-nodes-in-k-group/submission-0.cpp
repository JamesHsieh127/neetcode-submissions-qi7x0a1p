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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* cur=head;
        while(cur){
            n++;
            cur=cur->next;
        }
        cur=head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=nullptr;
        ListNode* p0=dummy;
        while(n>=k){
            for(int i=0; i<k; i++){
                ListNode* nxt=cur->next;
                cur->next=prev;
                prev=cur;
                cur=nxt;
            }
            ListNode* end=p0->next;
            p0->next->next=cur;
            p0->next=prev;
            p0=end;
            n-=k;
        }
        return dummy->next;
    }
};
