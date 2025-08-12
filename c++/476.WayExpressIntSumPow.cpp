/*2787. Ways to Express an Integer as Sum of Powers

Given two positive integers n and x.

Return the number of ways n can be expressed as the sum of the xth power of
unique positive integers, in other words, the number of sets of unique integers
[n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

Since the result can be very large, return it modulo 109 + 7.

For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.



Example 1:

Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 32 + 12 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd
power of unique integers. Example 2:

Input: n = 4, x = 1
Output: 2
Explanation: We can express n in the following ways:
- n = 41 = 4.
- n = 31 + 11 = 4.


Constraints:

1 <= n <= 300
1 <= x <= 5


Hint 1
You can use dynamic programming, where dp[k][j] represents the number of ways to
express k as the sum of the x-th power of unique positive integers such that the
biggest possible number we use is j. Hint 2 To calculate dp[k][j], you can
iterate over the numbers smaller than j and try to use each one as a power of x
to make our sum k.
*/
/*Approach:
1. Generate all possible numbers `i^x` where `i^x <= n`.

2. Use a 2D DP table: `dp[k][j]` = number of ways to express `k` as sum of
unique `x`-th powers of numbers up to `j`.

3. Base case: `dp[0][j] = 1` for all `j` (there's one way to form 0 — use no
numbers).

4. Transition:
    - For each `k` from 1 to n
    - For each `j` from 1 to max base
        - `dp[k][j] = dp[k][j-1]` (don't use j-th number)
        - If `k - (j^x) >= 0` then add `dp[k - j^x][j-1]` (use j-th number)


    */

class Solution {
  static constexpr int MOD = 1'000'000'007;

public:
  int numberOfWays(int n, int x) {
    // Find max base number i such that i^x <= n
    int maxBase = 1;
    while (pow(maxBase, x) <= n)
      maxBase++;
    maxBase--;

    // Precompute powers
    vector<int> powers(maxBase + 1, 0);
    for (int i = 1; i <= maxBase; ++i) {
      powers[i] = pow(i, x);
    }

    // dp[k][j] = number of ways to express k as sum of unique powers <=
    // powers[j]
    vector<vector<int>> dp(n + 1, vector<int>(maxBase + 1, 0));

    // Base case: number of ways to get sum 0 is 1 (use no numbers)
    for (int j = 0; j <= maxBase; ++j) {
      dp[0][j] = 1;
    }

    for (int k = 1; k <= n; ++k) {
      for (int j = 1; j <= maxBase; ++j) {
        // don't use j-th power
        dp[k][j] = dp[k][j - 1];
        // try to use j-th power if it fits
        if (k - powers[j] >= 0) {
          dp[k][j] = (dp[k][j] + dp[k - powers[j]][j - 1]) % MOD;
        }
      }
    }

    return dp[n][maxBase];
  }
};
// sub:
// https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/submissions/1731891444/?envType=daily-question&envId=2025-08-12
// sol:
// https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/solutions/7069842/2787-ways-to-express-an-integer-as-sum-o-900l/
