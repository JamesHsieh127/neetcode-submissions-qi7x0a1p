class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int, int> cnt;
        for(int& x:nums){
            cnt[x]++;
        }
        for(auto& [key, val]:cnt){
            if(val>n/3) ans.push_back(key);
        }
        return ans;
    }
};