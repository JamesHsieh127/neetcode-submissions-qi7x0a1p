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
    ListNode *middleNode(ListNode* head){
        ListNode *slow=head, *fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *reverseList(ListNode* head){
        ListNode *pre=nullptr, *cur=head;
        while(cur){
            ListNode *nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        ListNode *mid=middleNode(head);
        ListNode *head2=reverseList(mid);
        while(head2 && head2->next){
            ListNode *nxt=head->next;
            ListNode *nxt2=head2->next;
            head->next=head2;
            head=nxt;
            head2->next=nxt;
            head2=nxt2;
        }
    }
};
