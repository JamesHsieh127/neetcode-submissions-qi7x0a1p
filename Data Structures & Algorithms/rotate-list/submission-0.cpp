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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k|| !head|| !head->next) return head;
        ListNode* cur=head;
        int n=1;
        while(cur&& cur->next){
            n++;
            cur=cur->next;
        }
        int add=n-(k%n);
        if(add==n) return head;
        cur->next=head;
        while(add){
            cur=cur->next;
            add--;
        }
        ListNode* dummy=cur->next;
        cur->next=nullptr;
        return dummy;
    }
};
