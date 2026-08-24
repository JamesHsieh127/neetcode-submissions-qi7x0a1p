struct Node{
    int key;
    int val;
    int freq=1;
    Node* prev;
    Node* next;
    Node(int k, int v){
        key=k;
        val=v;
        prev=nullptr;
        next=nullptr;
    }
};
class LFUCache {
public:
    int capacity, minFreq;
    unordered_map<int, Node*> keyToNode, freqToDummy;
    Node* getNode(int key){
        if(!keyToNode.contains(key)){
            return nullptr;
        }
        Node* node=keyToNode[key];
        remove(node);
        Node* dummy=freqToDummy[node->freq];
        if(dummy->prev==dummy){
            freqToDummy.erase(node->freq);
            delete dummy;
            if(minFreq==node->freq){
                minFreq++;
            }
        }
        node->freq++;
        pushFront(node->freq, node);
        return node;
    }
    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    Node* newList(){
        Node* dummy=new Node(-1, -1);
        dummy->prev=dummy;
        dummy->next=dummy;
        return dummy;
    }
    void pushFront(int freq, Node* node){
        if(!freqToDummy.contains(freq)){
            freqToDummy[freq]=newList();
        }
        Node* dummy=freqToDummy[freq];
        node->prev=dummy;
        node->next=dummy->next;
        node->prev->next=node;
        node->next->prev=node;
    }
    LFUCache(int capacity) {
        this->capacity=capacity;
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
        if(keyToNode.size()==capacity){
            Node* dummy=freqToDummy[minFreq];
            Node* backNode=dummy->prev;
            keyToNode.erase(backNode->key);
            remove(backNode);
            delete backNode;
            if(dummy->prev==dummy){
                freqToDummy.erase(minFreq);
                delete dummy;
            }
        }
        node=new Node(key, value);
        keyToNode[key]=node;
        pushFront(1, node);
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */