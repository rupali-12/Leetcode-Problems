class Twitter {
public:
   int time=0;
   unordered_map<int, vector<pair<int, int>>>tweets;   // {time, tweedid}
   unordered_map<int, unordered_set<int>>following;   // follower->set of following

    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>result;

        priority_queue<vector<int>>pq;   // {time, tweetid, userId, idx}
         
        //  include self
        following[userId].insert(userId);

        // insert one one tweet of every user as start
        for(int user: following[userId]){
           if(tweets[user].empty()) continue;

            int idx = tweets[user].size()-1;
            auto [t, tid] = tweets[user][idx];
            pq.push({t, tid, user, idx});
        }

        // process queue
        while(!pq.empty() && result.size()<10){
            auto top = pq.top();
            pq.pop();

            int time = top[0];
            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];

            result.push_back(tweetId);

            // push next tweet of poped user if any next tweet is present
            if(idx>0){
                auto [nt, ntwid] = tweets[user][idx-1];
                pq.push({nt, ntwid, user, idx-1});
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        
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