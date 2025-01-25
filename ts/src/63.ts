// 355. Design Twitter
class Twitter {
  private tweetMap: Map<number, { timestamp: number; tweetId: number }[]>;
  private followMap: Map<number, Set<number>>;
  private timestamp: number;

  constructor() {
    this.tweetMap = new Map(); // Maps userId to their tweets [{timestamp, tweetId}]
    this.followMap = new Map(); // Maps userId to a set of followees
    this.timestamp = 0; // Global timestamp for ordering tweets
  }

  postTweet(userId: number, tweetId: number): void {
    if (!this.tweetMap.has(userId)) {
      this.tweetMap.set(userId, []);
    }
    this.tweetMap
      .get(userId)!
      .unshift({ timestamp: this.timestamp++, tweetId });
  }

  getNewsFeed(userId: number): number[] {
    const maxHeap: { timestamp: number; tweetId: number }[] = [];

    // Helper function to add tweets to the heap
    const addToHeap = (tweets: { timestamp: number; tweetId: number }[]) => {
      for (const tweet of tweets) {
        maxHeap.push(tweet);
      }
    };

    // Add user's tweets to the heap
    if (this.tweetMap.has(userId)) {
      addToHeap(this.tweetMap.get(userId)!);
    }

    // Add followees' tweets to the heap
    if (this.followMap.has(userId)) {
      for (const followeeId of this.followMap.get(userId)!) {
        if (this.tweetMap.has(followeeId)) {
          addToHeap(this.tweetMap.get(followeeId)!);
        }
      }
    }

    // Sort the heap by timestamp in descending order
    maxHeap.sort((a, b) => b.timestamp - a.timestamp);

    // Get the top 10 most recent tweets
    return maxHeap.slice(0, 10).map((tweet) => tweet.tweetId);
  }

  follow(followerId: number, followeeId: number): void {
    if (!this.followMap.has(followerId)) {
      this.followMap.set(followerId, new Set());
    }
    this.followMap.get(followerId)!.add(followeeId);
  }

  unfollow(followerId: number, followeeId: number): void {
    if (this.followMap.has(followerId)) {
      this.followMap.get(followerId)!.delete(followeeId);
    }
  }
}
//Your Twitter object will be instantiated and called as such:
var obj = new Twitter();
obj.postTweet(userId, tweetId);
var param_2 = obj.getNewsFeed(userId);
obj.follow(followerId, followeeId);
obj.unfollow(followerId, followeeId);

//sub: https://leetcode.com/problems/design-twitter/submissions/1519722888/
//sol: https://leetcode.com/problems/design-twitter/solutions/6326490/355-design-twitter6713-by-nalindalal2004-75jg/
