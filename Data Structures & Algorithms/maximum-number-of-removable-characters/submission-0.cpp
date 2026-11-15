class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int ans=0, m=s.size(), n=p.size(), k=removable.size();
        int left=-1, right=k;
        auto check=[&](int mid){
            vector<bool> isRemove(m, false);
            for(int i=0; i<=mid; i++){
                isRemove[removable[i]]=true;
            }
            int i=0, j=0;
            while(i<m&& j<n){
                if(isRemove[i]){
                    i++;
                    continue;
                }
                if(s[i]==p[j]){
                    j++;
                }
                i++;
            }
            return j==n;
        };
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(check(mid)) left=mid;
            else right=mid;
        }
        return left+1;
    }
};