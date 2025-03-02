/*312. Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with
a number on it represented by an array nums. You are asked to burst all the
balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1]
coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if
there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.



Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10


Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/
#include <algorithm>
#include <vector>
using namespace std;
/*
    int ans = 0;
    if (nums goes out of bound) {
      nums[i] = 1;
    }
    for (int i = 0; i < nums.size(); i++) {
      ans += nums[i - 1] * nums[i] * nums[i + 1];
    }
    return ans;
*/

class Solution {
public:
  int dp[302][302]; // Memoization table

  int burst(vector<int>& nums, int left, int right) {
    if (left > right)
      return 0; // Base case

    if (dp[left][right] != -1)
      return dp[left][right]; // Memoization check

    int maxCoins = 0;
    for (int i = left; i <= right; i++) {
      int coins = nums[left - 1] * nums[i] * nums[right + 1]; // Burst i
      coins += burst(nums, left, i - 1);                      // Left subarray
      coins += burst(nums, i + 1, right);                     // Right subarray

      maxCoins = max(maxCoins, coins);
    }

    return dp[left][right] = maxCoins;
  }

  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1); // Add 1 at start
    nums.push_back(1);            // Add 1 at end

    memset(dp, -1, sizeof(dp)); // Initialize DP table
    return burst(nums, 1, n);
  }
};
// sub: https://leetcode.com/problems/burst-balloons/submissions/1560028626/
// optimised:
class Solution1 {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1); // Add boundary 1 at start
    nums.push_back(1);            // Add boundary 1 at end

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // Process subarrays of increasing lengths
    for (int len = 1; len <= n; len++) {
      for (int left = 1; left <= n - len + 1; left++) {
        int right = left + len - 1;

        for (int i = left; i <= right; i++) {
          int coins = nums[left - 1] * nums[i] * nums[right + 1];
          coins += dp[left][i - 1];  // Coins from left subarray
          coins += dp[i + 1][right]; // Coins from right subarray

          dp[left][right] = max(dp[left][right], coins);
        }
      }
    }

    return dp[1][n];
  }
};
// sub: https://leetcode.com/problems/burst-balloons/submissions/1560029647/
// sol:
// https://leetcode.com/problems/burst-balloons/solutions/6484518/312-burst-balloons-by-nalindalal2004-pzg1/
