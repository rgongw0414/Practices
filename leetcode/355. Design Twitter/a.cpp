class Twitter {
private:
    // better SC using hash map, instead of fixed-size array
    unordered_map<int, unordered_set<int>> followingTable; // map uID to its following list (a hash set)
    // unordered_map<int, unordered_map<int, bool>> use the same amount memory as unordered_map<int, unordered_set<int>>, 
    // because they both map int to a bit (i.e. a bool value)
    vector<pair<int, int>> timeLine; // pair: posterUID, tweetID

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        timeLine.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        for (int i = timeLine.size() - 1; i >= 0; i--) {
            // start from the most recent posted tweet
            int posterUID = timeLine[i].first;
            int tweetID = timeLine[i].second;
            // poster is the user      // check if following
            if (posterUID == userId || followingTable[userId].find(posterUID) != followingTable[userId].end()) {
                feed.push_back(tweetID);
            }
            if (feed.size() == 10) break;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followingTable[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followingTable[followerId].erase(followeeId);
    }
};

// using fixed-size  array, not so good SC
class Twitter {
public:

    vector<vector<bool>> followingTable; // [uID][followingUID]
    vector<pair<int, int>> timeLine; // pair: posterUID, tweetID
    Twitter() : followingTable(501, std::vector<bool>(501, false)) {
        for (int i = 1; i <= 500; i++) {
            followingTable[i][i] = true; // you are following youself
        }
    }
    
    void postTweet(int userId, int tweetId) {
        timeLine.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        for (int i = timeLine.size() - 1; i >= 0; i--) {
            // start from the most recent posted tweet
            int posterUID = timeLine[i].first;
            int tweetID = timeLine[i].second;
            if (followingTable[userId][posterUID]) {
                feed.push_back(tweetID);
            }
            if (feed.size() == 10) break;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followingTable[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        followingTable[followerId][followeeId] = false;
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