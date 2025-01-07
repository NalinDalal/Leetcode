/* https://leetcode.com/problems/maximum-coins-from-k-consecutive-bags/description/

3413. Maximum Coins From K Consecutive Bags

There are an infinite amount of bags on a number line, one bag for each
coordinate. Some of these bags contain coins.

You are given a 2D array coins, where coins[i] = [li, ri, ci] denotes that every
bag from li to ri contains ci coins.

The segments that coins contain are non-overlapping.

You are also given an integer k.

Return the maximum amount of coins you can obtain by collecting k consecutive
bags.



Example 1:
Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
Output: 10
Explanation:Selecting bags at positions [3, 4, 5, 6] gives the maximum number of
coins: 2 + 0 + 4 + 4 = 10.

Example 2:
Input: coins = [[1,10,3]], k = 2
Output: 6
Explanation:Selecting bags at positions [1, 2] gives the maximum number of
coins: 3 + 3 = 6.


Constraints:
1 <= coins.length <= 105
1 <= k <= 109
coins[i] == [li, ri, ci]
1 <= li <= ri <= 109
1 <= ci <= 1000
The given segments are non-overlapping.
*/

#include <map>
#include <vector>
using namespace std;

// Intuition:
/* 1. Represent coin intervals with a difference array-like map.
2. Flatten the data into positions and their respective coin counts using prefix
sums.
3. Use a sliding window to find the maximum sum of k consecutive positions.*/
// Approach:
/* 1. Use a Map for Coin Changes:
    - Each interval [li, ri] with ci coins is represented by:
        - Adding ci coins to li (coinMap[li] += ci).
        - Subtracting ci coins from ri + 1 (coinMap[ri + 1] -= ci).
    - This creates a map where each key represents a coordinate, and the value
represents how the number of coins changes at that coordinate.

2. Flatten into Prefix Coins:
    - Traverse the map in sorted order of coordinates, maintaining a running
total (currentCoins) of coins at each position.
    - Store these positions and their respective currentCoins in a list
prefixCoins.

3. Apply Sliding Window Technique:
    - Traverse the prefixCoins list while maintaining a sliding window of size
k.
    - For each segment:
        - Add the coins in the current interval to windowSum and update the
window size.
        - If the window size exceeds k, shrink it from the left by subtracting
coins from the start of the window.
    - Keep track of the maximum coins obtained (maxCoins).
*/

#define ll long long

class Solution {
public:
  long long maximumCoins(vector<vector<int>>& x, int k) {
    ll ans = 0, n = x.size();

    x.insert(x.begin(), {0});
    sort(x.begin(), x.end());

    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++)
      pre[i] = pre[i - 1] + (x[i][1] - x[i][0] + 1) * (ll)x[i][2];

    for (int i = 1; i <= n; i++) {
      int l = i + 1, r = n, m, o = x[i][0] + k - 1;
      while (l <= r) {
        m = l + r >> 1;

        (o >= x[m][0] ? l = m + 1 : r = m - 1);
      }

      if (o >= x[r][1]) // if the point is covers all the intervals
        ans = max(ans, pre[r] - pre[i - 1]);
      else // if the point is not covers all the intervals
        ans =
            max(ans, pre[r - 1] - pre[i - 1] + (o - x[r][0] + 1) * (ll)x[r][2]);

      l = 1, r = i - 1, o = x[i][1] - k + 1;
      while (l <= r) {
        m = l + r >> 1;

        (o <= x[m][1] ? r = m - 1 : l = m + 1);
      }

      if (o <= x[l][0]) // if the point is covers all the intervals
        ans = max(ans, pre[i] - pre[l - 1]);
      else // if the point is not covers all the intervals
        ans = max(ans, pre[i] - pre[l] + (x[l][1] - o + 1) * (ll)x[l][2]);
    }

    return ans;
  }
};

// Time:
/* Constructing coinMap: 𝑂(𝑁), where 𝑁 is the number of intervals in coins.
Traversing coinMap: 𝑂(𝑀), where 𝑀 is the number of unique positions.
Sliding window traversal: 𝑂(𝑀).
Total: 𝑂(𝑁+𝑀).*/
// Space Complexity:coinMap and prefixCoins together use 𝑂(𝑀) space.
