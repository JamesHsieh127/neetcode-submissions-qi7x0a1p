class MyCalendar {
public:
    vector<pair<int,int>> nums;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto&[left, right]:nums){
            if(left<endTime&& right>startTime) return false;
        }
        nums.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */