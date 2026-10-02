class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) {
        int n=w.size();
        prefix.assign(n+1, 0);
        for(int i=1; i<=n; i++){
            prefix[i]=prefix[i-1]+w[i-1];
        }
    }
    
    int pickIndex() {
        int n=prefix.size();
        int target=rand()%prefix.back();
        int left=-1, right=n;
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(prefix[mid]>target) right=mid;
            else left=mid;
        }
        return right-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */