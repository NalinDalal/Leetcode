/*518. Coin Change II

You are given an integer array coins representing coins of different
denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of
money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.



Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10]
Output: 1


Constraints:
1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000*/

#include <vector>

using namespace std;

// make amount from coins member
// return total ways to make amount

// if coins sum goes over amount; break b/f it
// else add it to ways
// iterate coins in such a way that we can make amount
// maybe use a dp

// for (int i = 1; i <= amount; i++) {

// for (int j = 0; j < coins.size(); j++) {

//   dp[i] += dp[i - coins[j]];
const int MOD = 1e9 + 7;
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    // dp[i] will store the number of ways to make amount i using coins
    // vector<int> dp(amount + 1, 0);    //long long cause it causes a
    // integer overflow; use __int128_t
    vector<__int128_t> dp(amount + 1, 0);

    // Base case: 1 way to make amount 0 (using no coins)
    dp[0] = 1;

    for (int coin : coins) {
      for (int i = coin; i <= amount; i++) {
        // dp[i] += dp[i - coin];
        dp[i] = (dp[i] + dp[i - coin]) % MOD; // Prevent overflow with MOD
      }
    }

    return (dp[amount] > INT_MAX) ? -1 : (int)dp[amount];
  }
};

// issue reported:
// https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/27356

// cleaner code:
class Solution1 {
public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
      for (int j = coin; j <= amount; j++) {
        dp[j] += dp[j - coin];
      }
    }

    return dp[amount];
  }
};
// ye bhi run time de rha h
// accepted:
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    int m = coins.size(), n = amount;
    unsigned f[m + 1][n + 1];
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        f[i][j] = f[i - 1][j];
        if (j >= coins[i - 1]) {
          f[i][j] += f[i][j - coins[i - 1]];
        }
      }
    }
    return f[m][n];
  }
};
// sub: https://leetcode.com/problems/coin-change-ii/submissions/1553545020/
// sol:
// https://leetcode.com/problems/coin-change-ii/solutions/6461576/518-coin-change-ii-by-nalindalal2004-26p0/
