class Solution {
public:
    vector<int> path;
    bool dfs(vector<int>& matchsticks, int& target, int idx){
        int n=matchsticks.size();
        if(idx==n){
            return (path[0]==target&& path[1]==target&&
            path[2]==target&& path[3]==target);
        }
        for(int i=0; i<4 ;i++){
            if(path[i]+matchsticks[idx]>target) continue;
            path[i]+=matchsticks[idx];
            if(dfs(matchsticks, target, idx+1)) return true;
            path[i]-=matchsticks[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0, n=matchsticks.size();
        for(int& x:matchsticks) sum+=x;
        if(sum%4!=0|| n<4) return false;
        sum/=4;
        path.assign(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if(matchsticks[0]>sum) return false;
        return dfs(matchsticks, sum, 0);
    }
};