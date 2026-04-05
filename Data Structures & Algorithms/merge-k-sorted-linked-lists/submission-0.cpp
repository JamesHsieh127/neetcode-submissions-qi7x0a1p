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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        for(ListNode* l:lists){
            while(l){
                minHeap.push(l->val);
                l=l->next;
            }
        }
        while(!minHeap.empty()){
            cur->next=new ListNode(minHeap.top());
            minHeap.pop();
            cur=cur->next;
        }
        return dummy->next;
    }
};
