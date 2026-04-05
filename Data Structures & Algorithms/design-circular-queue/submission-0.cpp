class MyCircularQueue {
public:
    vector<int> buffer;
    int capacity;
    int front;
    int end;
    MyCircularQueue(int k) {
        this->capacity=k+1;
        this->front=0;
        this->end=0;
        buffer.resize(k+1, 0);    
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        buffer[end]=value;
        end=(end+1)%capacity;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front=(front+1)%capacity;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return buffer[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return buffer[(end-1+capacity)%capacity];
    }
    
    bool isEmpty() {
        return front==end;
    }
    
    bool isFull() {
        return front==(end+1)%capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */