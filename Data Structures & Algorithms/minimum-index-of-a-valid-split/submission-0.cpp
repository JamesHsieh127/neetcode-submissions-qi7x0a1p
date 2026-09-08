class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int m=nums.size(), maxVal=INT_MIN, maxFreq=INT_MIN;
        unordered_map<int, int> cnt1, cnt2;
        for(int& x:nums) cnt1[x]++;
        for(int i=0; i<m; i++){
            cnt2[nums[i]]++;
            if((cnt2[nums[i]]*2)>(i+1)&&
            (cnt1[nums[i]]-cnt2[nums[i]])*2>(m-i-1)){
                return i;
            }
        }
        return -1;
    }
};