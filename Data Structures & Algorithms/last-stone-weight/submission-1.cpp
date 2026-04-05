class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int x:stones){
            maxHeap.push(x);
        }
        while(maxHeap.size()>1){
            int x=maxHeap.top();
            maxHeap.pop();
            int y=maxHeap.top();
            maxHeap.pop();
            x-=y;
            if(x){
                maxHeap.push(x);
            }
        }
        return maxHeap.empty()?0:maxHeap.top();
    }
};
