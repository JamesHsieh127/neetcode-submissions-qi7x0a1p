class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.contains(val)) return false;
        int idx=mp.size();
        mp[val]=idx;
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!mp.contains(val)) return false;
        int idx=mp[val], lastVal=arr.back();
        arr[idx]=lastVal;
        arr.pop_back();
        mp[lastVal]=idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int randIdx=rand()%(arr.size());
        return arr[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */