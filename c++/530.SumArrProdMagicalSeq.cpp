/*3539. Find Sum of Array Product of Magical Sequences
You are given two integers, m and k, and an integer array nums.

A sequence of integers seq is called magical if:
seq has a size of m.
0 <= seq[i] < nums.length
The binary representation of 2seq[0] + 2seq[1] + ... + 2seq[m - 1] has k set
bits. The array product of this sequence is defined as prod(seq) = (nums[seq[0]]
* nums[seq[1]] * ... * nums[seq[m - 1]]).

Return the sum of the array products for all valid magical sequences.

Since the answer may be large, return it modulo 109 + 7.

A set bit refers to a bit in the binary representation of a number that has a
value of 1.



Example 1:

Input: m = 5, k = 5, nums = [1,10,100,10000,1000000]

Output: 991600007

Explanation:

All permutations of [0, 1, 2, 3, 4] are magical sequences, each with an array
product of 1013.

Example 2:

Input: m = 2, k = 2, nums = [5,4,3,2,1]

Output: 170

Explanation:

The magical sequences are [0, 1], [0, 2], [0, 3], [0, 4], [1, 0], [1, 2], [1,
3], [1, 4], [2, 0], [2, 1], [2, 3], [2, 4], [3, 0], [3, 1], [3, 2], [3, 4], [4,
0], [4, 1], [4, 2], and [4, 3].

Example 3:

Input: m = 1, k = 1, nums = [28]

Output: 28

Explanation:

The only magical sequence is [0].



Constraints:

1 <= k <= m <= 30
1 <= nums.length <= 50
1 <= nums[i] <= 108


Hint 1
Use Dynamic Programming
Hint 2
Let dp[i][j][mask] be the state after choosing i numbers (indices)
Hint 3
The partial sum S = 2^(seq[0]) + 2^(seq[1]) + ... + 2^(seq[i - 1]) has produced
exactly j set bits once you’ve fully propagated any carries

Hint 4
The mask represents the "window" of lower-order bits from S that have not yet
been fully processed (i.e. bits that might later create new set bits when
additional terms are added)

Hint 5
Use combinatorics

Hint 6
How many ways are
there to permute a sequence of entities where some are repetitive?
*/

using int64 = long long;
const int MOD = 1000000007;

int addmod(int a, int b) {
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}
int64 mulmod(int64 a, int64 b) { return (a * b) % MOD; }
int powmod(int64 a, int64 e) {
  int64 r = 1 % MOD;
  a %= MOD;
  while (e) {
    if (e & 1)
      r = (r * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1;
  }
  return (int)r;
}

class Solution {
public:
  int magicalSum(int m, int k, vector<int>& nums) {
    int n = (int)nums.size();
    // precompute factorials and inv factorials up to m
    vector<int64> fact(m + 1, 1), invfact(m + 1, 1);
    for (int i = 1; i <= m; i++)
      fact[i] = fact[i - 1] * i % MOD;
    invfact[m] = powmod(fact[m], MOD - 2);
    for (int i = m; i > 0; i--)
      invfact[i - 1] = invfact[i] * i % MOD;

    // precompute pow_nums[pos][c] = nums[pos]^c % MOD for c=0..m
    vector<vector<int>> pow_nums(n, vector<int>(m + 1, 1));
    for (int i = 0; i < n; i++) {
      pow_nums[i][0] = 1;
      for (int c = 1; c <= m; c++) {
        pow_nums[i][c] =
            (int)((int64)pow_nums[i][c - 1] * (nums[i] % MOD) % MOD);
      }
    }

    // Choose how many extra bits to process to let carries die out.
    // m <= 30, so extra 6 bits is safe (2^6 = 64 > 30).
    int extra = 6;
    int total_bits = n + extra;

    // DP by iterating bit positions.
    // dp[used][carry][ones] = current accumulated value (unordered-multiset
    // weight) dimensions: used=0..m, carry=0..m, ones=0..k (cap ones at k)
    auto make3d = [&](int A, int B, int C) {
      return vector<vector<vector<int>>>(
          A, vector<vector<int>>(B, vector<int>(C, 0)));
    };

    auto dp = make3d(m + 1, m + 1, k + 1);
    dp[0][0][0] = 1;

    for (int pos = 0; pos < total_bits; ++pos) {
      auto ndp = make3d(m + 1, m + 1, k + 1);
      for (int used = 0; used <= m; ++used) {
        for (int carry = 0; carry <= m; ++carry) {
          for (int onesCount = 0; onesCount <= k; ++onesCount) {
            int cur = dp[used][carry][onesCount];
            if (!cur)
              continue;
            // allowed copies c at this position:
            int maxc = (pos < n) ? (m - used) : 0; // for pos >= n, c must be 0
            for (int c = 0; c <= maxc; ++c) {
              int total = carry + c;
              int bit = total & 1;
              int carry_next = total >> 1;
              if (carry_next > m)
                continue; // safety bound
              int newOnes = onesCount + bit;
              if (newOnes > k)
                continue;

              // multiply by nums[pos]^c * invfact[c] (unordered weight)
              int64 mult = cur;
              if (c > 0) {
                if (pos < n) {
                  mult = (mult * pow_nums[pos][c]) % MOD;
                } else {
                  // pos >= n but c>0 impossible because maxc=0 when pos>=n
                }
                mult = (mult * invfact[c]) % MOD;
              }
              // if c==0, multiply by invfact[0] which is 1 (no-op)
              ndp[used + c][carry_next][newOnes] =
                  addmod(ndp[used + c][carry_next][newOnes], (int)mult);
            }
          }
        }
      }
      dp.swap(ndp);
    }

    // Final answer: dp[used=m][carry=0][ones=k] * m! % MOD
    int ans_unordered = dp[m][0][k];
    int64 ans = (int64)ans_unordered * fact[m] % MOD;
    return (int)ans;
  }
};
// sub:
// https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/submissions/1799124271/?envType=daily-question&envId=2025-10-12
// sol:
// https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/solutions/7268694/3539-find-sum-of-array-product-of-magica-0509/
