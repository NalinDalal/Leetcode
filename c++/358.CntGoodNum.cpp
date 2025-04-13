// 1922. Count Good Numbers
/* A digit string is good if the digits (0-indexed) at even indices are even and
the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are
even and the digits (5 and 2) at odd positions are prime. However, "3245" is not
good because 3 is at an even index but is not even. Given an integer n, return
the total number of good digit strings of length n. Since the answer may be
large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain
leading zeros.



Example 1:
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

Example 2:
Input: n = 4
Output: 400

Example 3:
Input: n = 50
Output: 564908303


Constraints:1 <= n <= 1015
Hint 1: Is there a formula we can use to find the count of all the good numbers?
Hint 2: Exponentiation can be done very fast if we looked at the binary bits of
n.
*/

// good string-> even index has even digit, odd index has prime digit
// given num n, return count of good string of length n

/* If n is the number of digits,Let:

evenPos = ceil(n / 2) → positions: 0, 2, 4, ...
oddPos = floor(n / 2) → positions: 1, 3, 5, ...

Then total good numbers: `good_count = (5 ^ evenPos) * (4 ^ oddPos) % MOD`

use binary exponentiation (a.k.a. fast power) to compute:
`a^b % mod` in $$O(log b)$$ time.
*/
class Solution {
public:
  const int MOD = 1'000'000'007;

  long long power(long long base, long long exp) {
    long long result = 1;
    base %= MOD;

    while (exp > 0) {
      if (exp % 2 == 1) {
        result = (result * base) % MOD;
      }
      base = (base * base) % MOD;
      exp /= 2;
    }

    return result;
  }

  int countGoodNumbers(long long n) {
    long long even = (n + 1) / 2;
    long long odd = n / 2;

    long long res = (power(5, even) * power(4, odd)) % MOD;
    return static_cast<int>(res);
  }
};
// sub:
// https://leetcode.com/problems/count-good-numbers/submissions/1605366975/?envType=daily-question&envId=2025-04-13
// sol:
// https://leetcode.com/problems/count-good-numbers/solutions/6645571/1922-count-good-numbers-by-nalindalal200-994j/
