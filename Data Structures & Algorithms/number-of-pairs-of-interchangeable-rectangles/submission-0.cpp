class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans=0;
        unordered_map<float, int> cnt;
        for(auto& a:rectangles){
            int x=a[0], y=a[1];
            float slope=(float)x/y;
            ans+=(cnt[slope]);
            cnt[slope]++;
        }
        return ans;
    }
};
