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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        sort(arr.begin(), arr.end());
        ListNode dummy;
        ListNode* cur=&dummy;
        for(int& x:arr){
            cur->next=new ListNode(x);
            cur=cur->next;
        }
        return dummy.next;
    }
};
