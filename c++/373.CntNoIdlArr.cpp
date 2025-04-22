/* 2338. Count the Number of Ideal Arrays
You are given two integers n and maxValue, which are used to describe an ideal
array.

A 0-indexed integer array arr of length n is considered ideal if the following
conditions hold:

Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
Return the number of distinct ideal arrays of length n. Since the answer may be
very large, return it modulo 109 + 7.



Example 1:

Input: n = 2, maxValue = 5
Output: 10
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
- Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
- Arrays starting with the value 3 (1 array): [3,3]
- Arrays starting with the value 4 (1 array): [4,4]
- Arrays starting with the value 5 (1 array): [5,5]
There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
Example 2:

Input: n = 5, maxValue = 3
Output: 11
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (9 arrays):
   - With no other distinct values (1 array): [1,1,1,1,1]
   - With 2nd distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2],
[1,1,2,2,2], [1,2,2,2,2]
   - With 2nd distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3],
[1,1,3,3,3], [1,3,3,3,3]
- Arrays starting with the value 2 (1 array): [2,2,2,2,2]
- Arrays starting with the value 3 (1 array): [3,3,3,3,3]
There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.


Constraints:
2 <= n <= 104
1 <= maxValue <= 104


Hint 1: Notice that an ideal array is non-decreasing.
Hint 2: Consider an alternative problem: where an ideal array must also be
strictly increasing. Can you use DP to solve it?
Hint 3: Will combinatorics help
to get an answer from the alternative problem to the actual problem?
*/

/* Intuition

The question requires us to find all arrays `arr` such that:

- `arr[i] ∈ [1, maxValue]`
- For all `i ∈ (0, n)`, `arr[i−1]` divides `arr[i]`.

In other words,
`arr[i] = arr[i−1] * kᵢ`, where `kᵢ ∈ ℕ`, and `i ∈ (0, n)`.
 */
/* Approach:
### Key Insight

We consider the number of arrays `arr` that end with a given value `x`.
It is not difficult to see that: $\prod_{i=0}^{n-1} k_i = x$


Conversely, each `kᵢ` must be a factor of `x`.
Thus, the problem transforms into finding how many different sequences of `kᵢ`
exist such that their product is `x`.

---

### Prime Factorization Approach

We can:
1. Use a prime sieve to factorize `x` into its prime factors.
2. Use combinatorics to count how many valid sequences of `kᵢ` can be formed
from those factors.

---

### Combinatorial Logic

Each `kᵢ` can be viewed as a slot.
We have `n` such slots, so we can place `n−1` dividers among them.
Suppose a prime factor occurs `p` times in the factorization of `x`.

Then we have:
- `p` identical items (prime powers),
- `n−1` dividers (splitting into `n` parts),
- Total positions: `p + n − 1`.

The number of ways to distribute the `p` items into `n` slots is:
**`C(n + p − 1, p)`**

Repeat this for each prime factor and multiply the results (multiplication
principle).

---

### Final Step

Enumerate all `x` in `[1, maxValue]`, calculate the corresponding number of
combinations for each `x`, and sum them up to get the final answer.
 */
const int MOD = 1e9 + 7, MAX_N = 1e4 + 10,
          MAX_P = 15; // There are up to 15 prime factors
int c[MAX_N + MAX_P][MAX_P + 1];
vector<int> ps[MAX_N]; // List of prime factor counts
int sieve[MAX_N];      // Minimum prime factor

class Solution {
public:
  Solution() {
    if (c[0][0]) {
      return;
    }
    for (int i = 2; i < MAX_N; i++) {
      if (sieve[i] == 0) {
        for (int j = i; j < MAX_N; j += i) {
          sieve[j] = i;
        }
      }
    }
    for (int i = 2; i < MAX_N; i++) {
      int x = i;
      while (x > 1) {
        int p = sieve[x];
        int cnt = 0;
        while (x % p == 0) {
          x /= p;
          cnt++;
        }
        ps[i].push_back(cnt);
      }
    }
    c[0][0] = 1;
    for (int i = 1; i < MAX_N + MAX_P; i++) {
      c[i][0] = 1;
      for (int j = 1; j <= min(i, MAX_P); j++) {
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
      }
    }
  }
  int idealArrays(int n, int maxValue) {
    long long ans = 0;
    for (int x = 1; x <= maxValue; x++) {
      long long mul = 1;
      for (int p : ps[x]) {
        mul = mul * c[n + p - 1][p] % MOD;
      }
      ans = (ans + mul) % MOD;
    }
    return ans;
  }
};
// Time complexity: $$O((n+ω(m))⋅ω(m)+mω(m))$$

// Space complexity: $$O((n+log(m))⋅log(m))$$
// sub:
// https://leetcode.com/problems/count-the-number-of-ideal-arrays/submissions/1614157878/?envType=daily-question&envId=2025-04-22
// sol:
// https://leetcode.com/problems/count-the-number-of-ideal-arrays/solutions/6675819/2338-count-the-number-of-ideal-arrays-by-pm80/
