#include <bits/stdc++.h>
using namespace std;

class Twitter
{
private:
    unordered_map<int, list<pair<int, int>>> tweets;

    unordered_map<int, unordered_set<int>> followers;

    int timestamp;

public:
    Twitter()
    {
        timestamp = 0;
    }
    void postTweet(int userId, int tweetId)
    {
        tweets[userId].emplace_front(timestamp++, tweetId);
        if (tweets[userId].size() > 10)
        {
            tweets[userId].pop_back();
        }
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> maxHeap;

        for (auto &tweet : tweets[userId])
        {
            maxHeap.push(tweet);
        }
        for (int followeeId : followers[userId])
        {
            if (tweets.find(followeeId) != tweets.end())
            {
                for (auto &tweet : tweets[followeeId])
                {
                    maxHeap.push(tweet);
                }
            }
        }
        vector<int> newsFeed;
        for (int i = 0; i < 10 && !maxHeap.empty(); i++)
        {
            newsFeed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return newsFeed;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            followers[followerId].insert(followeeId);
        }
    }
    void unfollow(int followerId, int followeeId)
    {
        if (followers[followerId].find(followeeId) != followers[followerId].end())
        {
            followers[followerId].erase(followeeId);
        }
    }
};

int main()
{
    return 0;
}