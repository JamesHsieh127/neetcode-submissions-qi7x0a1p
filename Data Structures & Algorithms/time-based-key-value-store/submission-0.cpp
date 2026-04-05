class TimeMap {
public:
    int binarySearch(vector<pair<int, string>>& nums, int target){
        int n=nums.size();
        int left=-1, right=n;
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(nums[mid].first>target){
                right=mid;
            }
            else{
                left=mid;
            }
        }
        return right;
    }
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.contains(key)){
            return "";
        }
        auto& a=mp[key];
        int idx=binarySearch(a, timestamp);
        if(!idx) return "";
        return a[idx-1].second;
    }
};