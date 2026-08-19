class FreqStack {
public:
    unordered_map<int, int> cnt;
    unordered_map<int, stack<int>> mp;
    int maxFreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        cnt[val]++;
        int freq=cnt[val];
        maxFreq=max(maxFreq, freq);
        mp[freq].push(val);
    }
    
    int pop() {
        int val=mp[maxFreq].top();
        mp[maxFreq].pop();
        cnt[val]--;
        if(mp[maxFreq].empty()) maxFreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */