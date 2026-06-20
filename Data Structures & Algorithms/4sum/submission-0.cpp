class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0; i<n-3; i++){
            long long x=nums[i];
            if(i>0&& nums[i]==nums[i-1]) continue;
            if(x+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(x+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1; j<n-2; j++){
                long long y=nums[j];
                if(j>i+1&& nums[j]==nums[j-1]) continue;
                if(x+y+nums[j+1]+nums[j+2]>target) break;
                if(x+y+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1, right=n-1;
                while(left<right){
                    long long sum=x+y+nums[left]+nums[right];
                    if(sum>target) right--;
                    else if(sum<target) left++;
                    else{
                        ans.push_back({(int)x, (int)y, nums[left], nums[right]});
                        left++;
                        right--;
                        while(left<right&& nums[left]==nums[left-1]) left++;
                        while(left<right&& nums[right]==nums[right+1]) right--;
                    }
                }
            }
        }
        return ans;
    }
};