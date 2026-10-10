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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        sort(arr.begin(), arr.end());
        ListNode dummy;
        dummy.val=INT_MIN;
        dummy.next=nullptr;
        ListNode* cur=&dummy;
        for(int& x:arr){
            ListNode* nxt=new ListNode(x);
            cur->next=nxt;
            cur=cur->next;
        }
        return dummy.next;
    }
};