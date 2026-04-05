class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> friends;
    int timestamp=0;
    Twitter() {
        this->timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<tuple<int, int, int, int>> maxHeap;
        friends[userId].insert(userId);
        for(int u:friends[userId]){
            auto& a=tweets[u];
            if(!a.empty()){
                int i=a.size()-1;
                maxHeap.push({a[i].first, a[i].second, u, i});
            }
        }
        while(!maxHeap.empty()&& ans.size()<10){
            auto[time, tweetId, u, i]=maxHeap.top();
            maxHeap.pop();
            ans.push_back(tweetId);
            i--;
            if(i>=0){
                maxHeap.push({tweets[u][i].first, tweets[u][i].second, u, i});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            friends[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            friends[followerId].erase(followeeId);
        }
    }
};
