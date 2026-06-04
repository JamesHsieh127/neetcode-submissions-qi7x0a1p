class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        unordered_map<int, int> cnt;
        sort(hand.begin(), hand.end());
        for(int& x:hand) cnt[x]++;
        for(int& x:hand){
            if(!cnt.contains(x)) continue;
            for(int i=0; i<groupSize; i++){
                int y=x+i;
                if(!cnt.contains(y)) return false;
                cnt[y]--;
                if(cnt[y]==0) cnt.erase(y);
            }
        }
        return true;
    }
};
