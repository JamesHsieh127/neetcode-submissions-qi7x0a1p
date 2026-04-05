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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* p0=dummy;
        for(int i=0; i<left-1; i++){
            p0=p0->next;
        }
        ListNode* prev=nullptr;
        ListNode* cur=p0->next;
        for(int i=left; i<=right; i++){
            ListNode* nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        p0->next->next=cur;
        p0->next=prev;
        return dummy->next;
    }
};