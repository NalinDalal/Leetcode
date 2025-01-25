/* 355. Design Twitter

Design a simplified version of Twitter where users can post tweets,
follow/unfollow another user, and is able to see the 10 most recent tweets in
the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by
the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in
the user's news feed. Each item in the news feed must be posted by users who the
user followed or by the user themself. Tweets must be ordered from most recent
to least recent. void follow(int followerId, int followeeId) The user with ID
followerId started following the user with ID followeeId. void unfollow(int
followerId, int followeeId) The user with ID followerId started unfollowing the
user with ID followeeId.


Example 1:
Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed",
"unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet
id -> [5]. return [5] twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet
ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after
tweet id 5. twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet
id -> [5], since user 1 is no longer following user 2.


Constraints:

1 <= userId, followerId, followeeId <= 500
0 <= tweetId <= 104
All the tweets have unique IDs.
At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and
unfollow. A user cannot follow himself.*/

#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>
using std::vector;

/* In the max heap I am inserting {time,userId,index,tweetId}
        initially push all the friends recent tweeets in the priority
        queue, their id , index as well as tweetId. Time will be first
        so that heap will work based on time
        make sure you also does the same for the user
        now everything same as merging K sorted arrays
<br>
In the while loop push topTweet to the answer and add
        corresponding userId's previous tweet into the priority queue
        if user has previous tweets then only.
        make sure you done this all things only for 10 times
    */
class Twitter {
private:
  map<int, list<pair<int, int>>> tweet;
  map<int, set<int>> followers;
  int timestamp;

public:
  Twitter() : timestamp(0) {}

  void postTweet(int userId, int tweetId) {
    tweet[userId].push_front({timestamp++, tweetId});
  }

  vector<int> getNewsFeed(int userId) {
    // max heap can be used to get the recent 10 tweets.
    priority_queue<pair<int, int>> recent_tweets;
    for (const auto& val : tweet[userId]) {
      recent_tweets.push(val);
    }

    // We have to get the tweets from followee also
    for (const auto& f : followers[userId]) {
      for (const auto& ft : tweet[f]) {
        recent_tweets.push(ft);
      }
    }

    // Now we need to find the recent 10 tweets.
    vector<int> tweets;
    int tweet_count = 0;
    while (!recent_tweets.empty() && tweet_count < 10) {
      tweets.push_back(recent_tweets.top().second);
      recent_tweets.pop();
      ++tweet_count;
    }
    return tweets;
  }

  void follow(int followerId, int followeeId) {
    followers[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    followers[followerId].erase(followeeId);
  }
};

int main() {
  // Your Twitter object will be instantiated and called as such:
  Twitter* obj = new Twitter();
  obj->postTweet(userId, tweetId);
  vector<int> param_2 = obj->getNewsFeed(userId);
  obj->follow(followerId, followeeId);
  obj->unfollow(followerId, followeeId);
  return 0;
}
// 67.13
//  sub: https://leetcode.com/problems/design-twitter/submissions/1519709660/
//  sol:
//  https://leetcode.com/problems/design-twitter/solutions/6326490/355-design-twitter6713-by-nalindalal2004-75jg/
