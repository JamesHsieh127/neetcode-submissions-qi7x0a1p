class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(char c:tasks){
            cnt[c-'A']++;
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        int m=cnt.size(), i=1, len=tasks.size();
        while(i<m&&
        cnt[i]==cnt[0]){
            i++;
        }
        return max(len, i+(n+1)*(cnt[0]-1));
    }
};
