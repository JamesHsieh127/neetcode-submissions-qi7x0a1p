class MyHashSet {
public:
    int size;
    vector<vector<int>> hashSet;
    MyHashSet() {
        this->size=1e3;
        this->hashSet.resize(size);
    }
    
    void add(int key) {
        int i=key%size;
        for(int& x:hashSet[i]){
            if(x==key) return;
        }
        hashSet[i].push_back(key);
    }
    
    void remove(int key) {
        int idx=key%size;
        vector<int>& arr=hashSet[idx];
        int n=arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]==key){
                arr.erase(arr.begin()+i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int i=key%size;
        for(int& x:hashSet[i]){
            if(x==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */