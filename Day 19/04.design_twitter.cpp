// https://leetcode.com/problems/design-twitter/

class Twitter {
public:
    map<int, set<int>> followers;
    map<int, vector<pair<int,int>>> post;
    long long int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for (pair<int,int> p: post[userId]) {
                pq.push(p);
        }
        for (int i: followers[userId]) {
            for (pair<int,int> p: post[i]) {
                pq.push(p);
            }
        }
        int c = 10;
        while(!pq.empty() && c--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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