class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans=0;
        vector<int> nums;
        for(auto& a:operations){
            if(a=="C"&& !nums.empty()){
                nums.pop_back();
            }
            else if(a=="D"&& !nums.empty()){
                nums.push_back(2*nums.back());
            }
            else if(a=="+"){
                int sum=0;
                for(int& x:nums) sum+=x;
                nums.push_back(sum);
            }
            else nums.push_back(stoi(a));
        }
        for(int& x:nums) ans+=x;
        return ans;
    }
};