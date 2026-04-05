/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool compare(Interval& a, Interval& b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        if(!n) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(intervals[0].end);
        for(int i=1; i<n; i++){
            if(intervals[i].start>=minHeap.top()){
                minHeap.pop();
            }
            minHeap.push(intervals[i].end);
        }
        return minHeap.size();
    }
};
