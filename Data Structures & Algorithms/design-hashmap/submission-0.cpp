class MyHashMap {
public:
    int size=1e3;
    vector<vector<pair<int, int>>> hashMap;
    MyHashMap() {
        this->hashMap.resize(size);
    }
    
    void put(int key, int value) {
        int i=key%size;
        for(auto&[k, v]:hashMap[i]){
            if(k==key){
                v=value;
                return;
            }
        }
        hashMap[i].push_back({key, value});
    }
    
    int get(int key) {
        int i=key%size;
        for(auto&[k, v]:hashMap[i]){
            if(k==key){
                return v;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int i=key%size;
        int n=hashMap[i].size();
        for(int j=0; j<n; j++){
            auto&[k, v]=hashMap[i][j];
            if(k==key){
                hashMap[i].erase(hashMap[i].begin()+j);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */