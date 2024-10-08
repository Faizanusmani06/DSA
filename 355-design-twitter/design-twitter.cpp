class Twitter {
    unordered_map<int, unordered_set<int>> friends;
    unordered_map <int, vector<pair<int, int>>> tweets;
    int time = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        vector<int> ans;

        for (auto& it : friends[userId]) {
            if (tweets[it].size()) {
                auto [t, tId] = tweets[it].back();
                pq.push({t, it, int(tweets[it].size()) - 1, tId});
            }
        }
        if (tweets[userId].size()) {
            auto [t, tId] = tweets[userId].back();
            pq.push({t, userId, int(tweets[userId].size()) - 1, tId});
        }


        int k = 10;

        while(k>0 && !pq.empty()) {
            vector<int> v = pq.top();
            pq.pop();
            ans.push_back(v[3]);

            if(v[2] != 0) {
                auto [newTime, newTweetId] = tweets[v[1]][v[2] - 1];

                pq.push({newTime, v[1], v[2] - 1, newTweetId});
            }
            k--;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (friends[followerId].find(followeeId) != friends[followerId].end()) {
            friends[followerId].erase(followeeId);
        }
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