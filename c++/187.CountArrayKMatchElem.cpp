/* 3405. Count the Number of Arrays with K Matching Adjacent Elements

You are given three integers n, m, k. A good array arr of size n is defined as
follows: Each element in arr is in the inclusive range [1, m]. Exactly k indices
i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i]. Return the
number of good arrays that can be formed.

Since the answer may be very large, return it modulo 109 + 7.



Example 1:
Input: n = 3, m = 2, k = 1
Output: 4

Explanation:
There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
Hence, the answer is 4.

Example 2:
Input: n = 4, m = 2, k = 2
Output: 6

Explanation:
The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2,
2, 1, 1] and [2, 2, 2, 1]. Hence, the answer is 6.

Example 3:
Input: n = 5, m = 2, k = 0
Output: 2
Explanation:The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the
answer is 2.


Constraints:
1 <= n <= 105
1 <= m <= 105
0 <= k <= n - 1*/

// good array definition:
//  a[i] is in range [1,m]-> 1<=a[i]<=m
//  k indices statisfy condition: arr[i - 1] == arr[i]; 1 <= i < n
//  return number of good arrays

/* dp[i][j] represents the number of ways to construct the first 𝑖 elements
of the array such that there are exactly 𝑗 indices 𝑥 satisfying
𝑎𝑟𝑟[𝑥−1]==𝑎𝑟𝑟[𝑥].
        * If 𝑎𝑟𝑟[𝑖]==𝑎𝑟𝑟[𝑖−1], then we increase the count of adjacent equal
elements by 1.
    * dp[i][j]=dp[i−1][j]×(m−1) (choosing a different value from 𝑎𝑟𝑟[𝑖−1]).
𝑑𝑝[𝑖][𝑗]+=𝑑𝑝[𝑖−1][𝑗−1] (choosing the same value as 𝑎𝑟𝑟[𝑖−1]).
*Base Case:𝑑𝑝[1][0]=𝑚: For the first element, all 𝑚 choices are valid, and there
are no adjacent equal elements.
* Result:𝑑𝑝[𝑛][𝑘]: The number of arrays of length
𝑛 with exactly 𝑘 adjacent equal indices.*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int countGoodArrays(int n, int m, int k) {

    // DP table: dp[i][j] -> number of arrays of length i with j adjacent pairs
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    int MOD = 1e9 + 7;

    // Base case: for arrays of length 1, there are no adjacent pairs
    dp[1][0] = m;

    // Fill the DP table
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        // Option 1: arr[i] is different from arr[i-1]
        dp[i][j] = (1LL * dp[i - 1][j] * (m - 1)) % MOD;

        // Option 2: arr[i] is the same as arr[i-1]
        if (j > 0) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        }
      }
    }

    // The answer is the number of arrays of length n with exactly k adjacent
    // pairs
    return dp[n][k];
  }
};

// Time: O(n*k)
// Space: O(n*k)

// Memory Optimisation:
// DP table only depends on the previous row (𝑖−1) for transitions. Hence, we
// can use a rolling array to reduce the space complexity to 𝑂(𝑘)

// Optimized Approach:
/*Instead of maintaining the entire 𝑛×𝑘 DP table, use two 1D arrays:
1. prev to store the previous row's values.
2. curr to compute the current row's values.*/
class Solution1 {
public:
  int countGoodArrays(int n, int m, int k) {
    const int MOD = 1e9 + 7;

    // Initialize DP arrays
    vector<int> prev(k + 1, 0), curr(k + 1, 0);

    // Base case: for arrays of length 1, no adjacent pairs exist
    prev[0] = m;

    // Fill DP table
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        // Reset current state
        curr[j] = 0;

        // Option 1: arr[i] is different from arr[i-1]
        curr[j] = (1LL * prev[j] * (m - 1)) % MOD;

        // Option 2: arr[i] is the same as arr[i-1]
        if (j > 0) {
          curr[j] = (curr[j] + prev[j - 1]) % MOD;
        }
      }
      // Swap prev and curr for the next iteration
      prev = curr;
    }

    // The answer is the number of arrays of length n with exactly k adjacent
    // pairs
    return prev[k];
  }
};

// Final
/*1. Edge Case Handling :
If k < 0 or k > n - 1, return 0 since it's impossible to have such arrays.

2. Precompute Factorials :
Compute factorials from `1` to `n - 1` modulo `10^9 +7`.

3. Precompute Modular Inverses :
Use Modular Exponentiation `a ^ (b - 2) mod b` to calculate modular inverses of
the factorials for combinatorial calculations.

4. Compute Combinations :
Calculate `C(n - 1, k) = factorial(n - 1) / (factorial(k) * factorial(n - 1 -
k))`.

5. Compute Power of m-1 :
Raise `m - 1` to the power of `n - k - 1` using modular exponentiation to count
valid configurations of differing indices.

6. Combine Results :
Multiply combinations, `m`, and powers of `m - 1`, and return the `result modulo
10 ^9 +7`.
*/

class Solution2 {
public:
  int countGoodArrays(int n, int m, int k) {
    const int MOD = 1'000'000'007;

    // Step 1: Handle edge cases
    if (k < 0 || k > n - 1) {
      return 0;
    }

    // Step 2: Precompute factorials
    vector<long long> factorial(n, 1);
    for (int i = 1; i < n; i++) {
      factorial[i] = factorial[i - 1] * i % MOD;
    }

    // Step 3: Precompute modular inverses using modular exponentiation
    vector<long long> invFact(n);
    invFact[n - 1] = powMod(factorial[n - 1], MOD - 2, MOD);
    for (int i = n - 2; i >= 0; i--) {
      invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    // Step 4: Compute combinations for choosing k indices
    long long combination = 0;
    if (k <= n - 1) {
      combination =
          factorial[n - 1] * invFact[k] % MOD * invFact[n - 1 - k] % MOD;
    }

    // Step 5: Compute power of (m-1) for remaining positions
    long long power = 1;
    if (n - k - 1 >= 0) {
      power = powMod(m - 1, n - k - 1, MOD);
    }

    // Step 6: Calculate result by combining values
    long long result = combination * m % MOD;
    result = result * power % MOD;

    return (int)result;
  }

private:
  // Helper function for modular exponentiation
  long long powMod(long long x, long long y, long long mod) {
    long long res = 1;
    x %= mod;

    while (y > 0) {
      if (y & 1)
        res = res * x % mod;
      x = x * x % mod;
      y >>= 1;
    }

    return res;
  }
};
// Time: O(n*k)
// Space: O(n*k)
//  31.26%
//  sub:
//  https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/submissions/1510110466/

// 100%
//  Time:  O(n + logm)
//  Space: O(n)

// combinatorics, fast exponentiation
static const int MOD = 1e9 + 7;
vector<int64_t> FACT = {1, 1};
vector<int64_t> INV = {1, 1};
vector<int64_t> INV_FACT = {1, 1};
int nCr(int n, int k) {
  while (size(INV) <= n) { // lazy initialization
    FACT.emplace_back((FACT.back() * size(INV)) % MOD);
    INV.emplace_back(
        ((INV[MOD % size(INV)]) * (MOD - MOD / size(INV))) %
        MOD); // https://cp-algorithms.com/algebra/module-inverse.html
    INV_FACT.emplace_back((INV_FACT.back() * INV.back()) % MOD);
  }
  return (((FACT[n] * INV_FACT[n - k]) % MOD) * INV_FACT[k]) % MOD;
}

class Solution3 {
public:
  int countGoodArrays(int n, int m, int k) {
    const auto& powmod = [&](int a, int b) {
      a %= MOD;
      int64_t result = 1;
      while (b) {
        if (b & 1) {
          result = result * a % MOD;
        }
        a = int64_t(a) * a % MOD;
        b >>= 1;
      }
      return result;
    };

    return (nCr(n - 1, k) * (m * powmod(m - 1, (n - 1) - k) % MOD)) % MOD;
  }
};

// sub(100%):https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/submissions/1510138923/
// sol:
// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/solutions/6852435/3405-count-the-number-of-arrays-with-k-m-3sli/
