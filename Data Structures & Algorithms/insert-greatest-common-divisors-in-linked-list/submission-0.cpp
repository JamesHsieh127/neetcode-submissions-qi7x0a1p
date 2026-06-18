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
    int gcd(int a, int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head||!head->next) 
            return head;
        ListNode* cur=head;
        while(cur&&cur->next){
            int gcdN=gcd(cur->val, cur->next->val);
            ListNode* newNode= new ListNode(gcdN);
            newNode->next = cur->next;
            cur->next= newNode;
            cur= newNode->next;
        }
        return head;
    }
};
