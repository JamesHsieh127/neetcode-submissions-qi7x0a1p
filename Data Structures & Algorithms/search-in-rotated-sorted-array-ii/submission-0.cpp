class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_set<int> st;
        for(int& x:nums) st.insert(x);
        for(int x:st){
            if(x==target) return true;
        }
        return false;
    }
};