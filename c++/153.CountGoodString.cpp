/*
https://leetcode.com/problems/count-ways-to-build-good-strings/description/?envType=daily-question&envId=2024-12-30

2466. Count Ways To Build Good Strings

Given the integers zero, one, low, and high, we can construct a string by
starting with an empty string, and then at each step perform either of the
following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length
between low and high (inclusive). Return the number of different good strings
that can be constructed satisfying these properties. Since the answer can be
large, return it modulo 109 + 7.


Example 1:
Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation:
One possible valid good string is "011".
It can be constructed as follows: "" -> "0" -> "01" -> "011".
All binary strings from "000" to "111" are good strings in this example.

Example 2:
Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".


Constraints:
1 <= low <= high <= 105
1 <= zero, one <= low
*/

// Approach:
// 1. Declare the state array `dp` as a global variable by using C-array; let
// `mod=1e9+7`
// 2. define the recursive function `long long good(int n, int x0, int x1)` with
// `dp`
// 3. In `countGoodStrings`, if zero > one: `swap(zero, one)`
// 4. fill `dp` with `-1`
// 5. return ``(good(high, zero, one)-good(low-1, zero, one)+mod)%mod``

class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    const int mod = 1e9 + 7;
    int dp[100001] = {0};
    dp[0] = 1;
    for (int i = 1; i <= high; i++) {
      long long ans = 1;
      if (i >= zero)
        ans += dp[i - zero];
      if (i >= one)
        ans += dp[i - one];
      dp[i] = ans % mod;
    }
    return (dp[high] - dp[low - 1] + mod) % mod;
  }
};

// Time: O(n)
// Space: O(n)
// 98.43%
// submission:
// https://leetcode.com/problems/count-ways-to-build-good-strings/submissions/1492095416/?envType=daily-question&envId=2024-12-30
//
