class Twitter {
public:
    unordered_map<int, unordered_set<int>> f;
    vector<pair<int, int>> feed;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        feed.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(int i=feed.size()-1;i>=0;i--) {
            auto it = feed[i];
            if(userId == it.first || f[userId].contains(it.first)) {
                ans.push_back(it.second);
                if(ans.size() == 10) break;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        f[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */