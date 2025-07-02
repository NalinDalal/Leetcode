/*3333. Find the Original Typed String II
Alice is attempting to type a specific string on her computer. However, she
tends to be clumsy and may press a key for too long, resulting in a character
being typed multiple times.

You are given a string word, which represents the final output displayed on
Alice's screen. You are also given a positive integer k.

Return the total number of possible original strings that Alice might have
intended to type, if she was trying to type a string of size at least k.

Since the answer may be very large, return it modulo 109 + 7.



Example 1:

Input: word = "aabbccdd", k = 7

Output: 5

Explanation:

The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and
"abbccdd".

Example 2:

Input: word = "aabbccdd", k = 8

Output: 1

Explanation:

The only possible string is "aabbccdd".

Example 3:

Input: word = "aaabbb", k = 3

Output: 8



Constraints:

1 <= word.length <= 5 * 105
word consists only of lowercase English letters.
1 <= k <= 2000

Hint 1
Instead of solving for at least k, can we solve for at most k - 1 length?
*/

/*Intuition:
- Typing the original string (with potential long key presses) resulted in the
final string word

- The original string length is at least k

- A character in the original string can be repeated one or more times in word
due to long key presses

- For every group of consecutive same characters in word, Alice must have typed
it at least once, and at most as many times as appear in word.

- So for a group like "aaa" → Alice could've intended to type "a", "aa", or
"aaa".
*/

/* Solution:
- Use KnapSack
- let `groupLens` be the array of counts of each character group.
- Let `dp[i]` be the number of ways to make a total intended length of `i`.
- Count all combinations of choosing x_i from [1 ... groupLens[i]] for each
group, such that:
```cpp
sum(x_1 + x_2 + ... + x_N) >= k
```

## DP
- dp[0] = 1 (base case: one way to form length 0)

- For each group length cnt, update dp as:

For each `total = MAX ... 0`:
```cpp
dp[total + i] += dp[total] for i in [1..cnt]
```

This can be done efficiently with prefix sums (or sliding window).
*/
class Solution {
public:
  int possibleStringCount(string word, int k) {
    int n = word.size(), cnt = 1;
    vector<int> freq;
    for (int i = 1; i < n; ++i) {
      if (word[i] == word[i - 1]) {
        ++cnt;
      } else {
        freq.push_back(cnt);
        cnt = 1;
      }
    }
    freq.push_back(cnt);

    int ans = 1;
    for (int o : freq) {
      ans = static_cast<long long>(ans) * o % mod;
    }

    if (freq.size() >= k) {
      return ans;
    }

    vector<int> f(k), g(k, 1);
    f[0] = 1;
    for (int i = 0; i < freq.size(); ++i) {
      vector<int> f_new(k);
      for (int j = 1; j < k; ++j) {
        f_new[j] = g[j - 1];
        if (j - freq[i] - 1 >= 0) {
          f_new[j] = (f_new[j] - g[j - freq[i] - 1] + mod) % mod;
        }
      }
      vector<int> g_new(k);
      g_new[0] = f_new[0];
      for (int j = 1; j < k; ++j) {
        g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
      }
      f = move(f_new);
      g = move(g_new);
    }
    return (ans - g[k - 1] + mod) % mod;
  }

private:
  static const int mod = 1000000007;
};
// sub:
// https://leetcode.com/problems/find-the-original-typed-string-ii/submissions/1683820830/
// sol:
// https://leetcode.com/problems/find-the-original-typed-string-ii/solutions/6911084/3333-find-the-original-typed-string-ii/
