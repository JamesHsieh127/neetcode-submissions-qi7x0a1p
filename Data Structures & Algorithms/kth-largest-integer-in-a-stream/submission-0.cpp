class KthLargest {
public:
    int kth;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->kth=k;
        for(int x:nums){
            add(x);
        }    
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size()>kth){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
