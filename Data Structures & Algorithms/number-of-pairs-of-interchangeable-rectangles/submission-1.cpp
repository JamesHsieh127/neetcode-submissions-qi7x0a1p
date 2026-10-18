class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans=0;
        map<pair<int, int>, long long> cnt;
        for(auto& a:rectangles){
            long long x=a[0], y=a[1];
            long long com=gcd(x,y);
            x/=com;
            y/=com;
            pair<int, int> slope={x,y};
            ans+=cnt[slope];
            cnt[slope]++;
        }
        return ans;
    }
};
