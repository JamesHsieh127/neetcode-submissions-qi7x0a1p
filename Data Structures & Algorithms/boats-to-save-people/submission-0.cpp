class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int left=0, right=n-1, ans=0;
        sort(people.begin(), people.end());
        while(left<=right){
            if(people[left]+people[right]<=limit){
                left++;
            }
            right--;
            ans++;
        }
        return ans;
    }
};