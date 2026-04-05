struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k=0, int v=0):key(k), val(v){};
};

class LRUCache {
public:
    int capacity=0;
    Node* dummy;
    unordered_map<int, Node*> keyToNode;
    
    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void pushToFront(Node* node){
        node->next=dummy->next;
        node->prev=dummy;
        dummy->next->prev=node;
        dummy->next=node;
    }

    Node* getNode(int key){
        Node* ans=nullptr;
        if(keyToNode.contains(key)){
            ans=keyToNode[key];
            removeNode(ans);
            pushToFront(ans);
        }
        return ans;
    }

    LRUCache(int capacity) {
        this->capacity=capacity;
        dummy=new Node();
        dummy->prev=dummy;
        dummy->next=dummy;
    }
    
    int get(int key) {
        Node* node=getNode(key);
        return node?node->val:-1;
    }
    
    void put(int key, int value) {
        Node* node=getNode(key);
        if(node){
            node->val=value;
            return;
        }
        keyToNode[key]=new Node(key, value);
        pushToFront(keyToNode[key]);
        if(keyToNode.size()>capacity){
            Node* end=dummy->prev;
            keyToNode.erase(end->key);
            removeNode(end);
            delete end;
        }
    }
};
