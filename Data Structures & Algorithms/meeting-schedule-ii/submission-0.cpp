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
        int ans=1, n=intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        for(int i=0; i<n-1; i++){
            if(intervals[i].end>intervals[i+1].start){
                ans++;
            }
        }
        return ans;
    }
};
