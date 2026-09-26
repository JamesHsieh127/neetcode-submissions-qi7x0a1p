class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(), left=0, ans=INT_MIN;
        unordered_map<int, int> cnt;
        for(int right=0; right<n; right++){
            cnt[fruits[right]]++;
            if(cnt.size()>2){
                cnt[fruits[left]]--;
                if(cnt[fruits[left]]==0){
                    cnt.erase(fruits[left]);
                }
                left++;
            }
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};