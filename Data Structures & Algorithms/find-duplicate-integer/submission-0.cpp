class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0, head=0;
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                break;
            }
        }
        while(slow!=head){
            slow=nums[slow];
            head=nums[head];
        }
        return slow;
    }
};
