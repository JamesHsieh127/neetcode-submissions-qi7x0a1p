class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size(), left=0, ans=0;
        deque<int> maxQ, minQ;
        for(int right=0; right<n; right++){
            int x=nums[right];
            while(!minQ.empty()&& 
            x<=nums[minQ.back()]){
                minQ.pop_back();
            }
            minQ.push_back(right);
            while(!maxQ.empty()&&
            x>=nums[maxQ.back()]){
                maxQ.pop_back();
            }
            maxQ.push_back(right);
            while(nums[maxQ.front()]-nums[minQ.front()]>limit){
                left++;
                if(minQ.front()<left) minQ.pop_front();
                if(maxQ.front()<left) maxQ.pop_front();
            }
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};