class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ans(3, 0);
        for(auto& a:triplets){
            if(a[0]<=target[0]&&
            a[1]<=target[1]&&
            a[2]<=target[2]){
                ans[0]=max(ans[0], a[0]);
                ans[1]=max(ans[1], a[1]);
                ans[2]=max(ans[2], a[2]);
            }
        }
        return ans==target;
    }
};
