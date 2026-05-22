struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val, ListNode* next):val(val), next(next){}
};
class LinkedList {
public:
    ListNode* head;
    ListNode* tail;
    LinkedList() {
        head=new ListNode(-1, nullptr);
        tail=head;
    }

    int get(int index) {
        ListNode* cur=head->next;
        int i=0;
        while(cur){
            if(i==index) return cur->val;
            i++;
            cur=cur->next;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* newNode=new ListNode(val);
        newNode->next=head->next;
        head->next=newNode;
        if(!newNode->next){
            tail=newNode;
        }
    }
    
    void insertTail(int val) {
        tail->next=new ListNode(val);
        tail=tail->next;
    }

    bool remove(int index) {
        int i=0;
        ListNode* cur=head;
        while(cur&& i<index){
            i++;
            cur=cur->next;
        }
        if(cur&& cur->next){
            if(cur->next==tail){
                tail=cur;
            }
            ListNode* delNode=cur->next;
            cur->next=cur->next->next;
            delete delNode;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> ans;
        ListNode* cur=head->next;
        while(cur){
            ans.push_back(cur->val);
            cur=cur->next;
        }
        return ans;
    }
};
