struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr){};
};
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int sz;
    MyLinkedList() {
        this->head=nullptr;
        this->tail=nullptr;
        this->sz=0;
    }
    
    int get(int index) {
        if(index>=sz|| index<0) return -1;
        Node* cur=head;
        for(int i=0; i<index; i++){
            cur=cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* cur=new Node(val);
        cur->next=head;
        head=cur;
        if(sz==0) tail=cur;
        sz++;
    }
    
    void addAtTail(int val) {
        Node* cur=new Node(val);
        if(sz==0){
            head=cur;
            tail=cur;
        }
        tail->next=cur;
        tail=cur;
        sz++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>sz|| index<0) return;
        if(index==0){
            addAtHead(val);
            return;
        }
        else if(index==sz){
            addAtTail(val);
            return;
        }
        Node* cur=head;
        for(int i=0; i<index-1; i++){
            cur=cur->next;
        }
        Node* node=new Node(val);
        node->next=cur->next;
        cur->next=node;
        sz++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=sz|| index<0) return;
        if(index==0){
            head=head->next;
            sz--;
            return;
        }
        Node* cur=head;
        for(int i=0; i<index-1; i++){
            cur=cur->next;
        }
        cur->next=cur->next->next;
        if(index==sz-1) tail=cur;
        sz--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */