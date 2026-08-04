class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        unordered_set<int> st;
        for(int right=0; right<n; right++){
            if(st.contains(nums[right])) return true;
            st.insert(nums[right]);
            while(right-left==k){
                st.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};
