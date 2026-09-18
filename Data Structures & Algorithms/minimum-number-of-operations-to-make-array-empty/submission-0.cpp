class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(), ans=0;
        unordered_map<int, int> cnt;
        for(int& x:nums) cnt[x]++;
        for(auto&[x, freq]:cnt){
            if(freq==1) return -1;
            ans+=(freq/3);
            if(freq%3) ans++; 
        }
        return ans;
    }
};