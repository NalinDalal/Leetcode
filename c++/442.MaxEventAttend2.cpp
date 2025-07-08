/*1751. Maximum Number of Events That Can Be Attended II
You are given an array of events where events[i] = [startDayi, endDayi, valuei].
The ith event starts at startDayi and ends at endDayi, and if you attend this
event, you will receive a value of valuei. You are also given an integer k which
represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you
must attend the entire event. Note that the end day is inclusive: that is, you
cannot attend two events where one of them starts and the other ends on the same
day.

Return the maximum sum of values that you can receive by attending events.



Example 1:



Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4
+ 3 = 7. Example 2:



Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do
not have to attend k events. Example 3:



Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events.
Pick the highest valued three.


Constraints:

1 <= k <= events.length
1 <= k * events.length <= 106
1 <= startDayi <= endDayi <= 109
1 <= valuei <= 106

Hint 1
Sort the events by its startTime.
Hint 2
For every event, you can either choose it and consider the next event available,
or you can ignore it. You can efficiently find the next event that is available
using binary search.
*/

/*Approach
1. sort the event by startTime
2. Use DP + Binary Search:
    - dp[i][k] = max value starting from event i with k events left to pick.

3. At each event, choose:
    - Take it: Add its value + next non-overlapping event via binary search.
    - Skip it: Try next event with same k.
*/
/*Steps:
1. Sort events by startTime.

2. Use memoization: `dp[index][remaining_k]`.

3. Use binary search to find the next non-overlapping event whose `startTime >
current endTime`.

tle
optimisation:
1. Convert to Bottom-Up DP (Iterative → much faster).

2. Use std::lower_bound instead of custom binary search.

3. Compress state: 1D DP for k levels, from back to front.


*/

class Solution {
public:
  int maxValue(vector<vector<int>>& events, int k) {
    int n = events.size();
    sort(events.begin(), events.end()); // sort by start time

    // Precompute next available event index using binary search
    vector<int> nextIndex(n, n);
    vector<int> startTimes;
    for (auto& e : events)
      startTimes.push_back(e[0]);

    for (int i = 0; i < n; ++i) {
      int end = events[i][1];
      // Find first event whose start > current end
      nextIndex[i] =
          lower_bound(startTimes.begin(), startTimes.end(), end + 1) -
          startTimes.begin();
    }

    // DP table: dp[i][j] = max value starting at i with j picks
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = n - 1; i >= 0; --i) {
      for (int j = 1; j <= k; ++j) {
        dp[i][j] = max(dp[i + 1][j], events[i][2] + dp[nextIndex[i]][j - 1]);
      }
    }

    return dp[0][k];
  }
};

// sub:
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/submissions/1690498819/?envType=daily-question&envId=2025-07-08
// sol:
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/solutions/6934148/1751-maximum-number-of-events-that-can-b-xrep/
