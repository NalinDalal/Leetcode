/* 3335. Total Characters in String After Transformations I

You are given a string s and an integer t, representing the number of
transformations to perform. In one transformation, every character in s is
replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a'
is replaced with 'b', 'b' is replaced with 'c', and so on. Return the length of
the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.



Example 1:

Input: s = "abcyy", t = 2

Output: 7

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'
String after the first transformation: "bcdzz"
Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.
Example 2:

Input: s = "azbk", t = 1

Output: 5

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'
String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.


Constraints:
1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 105
*/

// repeat the function t times, like while t>0 apply operation
// make a function named transform, do shit in it
// while(t>0){
// do transformation
// }
// transformation(){
// iterate, if s[i]=='z' replace with 'ab'
// else replace s[i] with next char
// return s
// }
// return s.length()

// optimisation:
/* We define `f(i, c)` as the number of occurrences of the character `c` in the
string after `i` transformations. For sake of clarity and ease of notation, we
let `c ∈ [0, 26)`, which corresponds to the 26 characters from `'a'` to `'z'` in
sequence.

Initially, each `f(0, c)` represents the number of occurrences of `c` in the
given string `s`. As we iterate from `f(i−1,⋯)` to `f(i,⋯)`:

- If `c = 0`, corresponding to `'a'`, it can only be converted from `'z'`,
therefore:
  **`f(i, 0) = f(i−1, 25)`**

- If `c = 1`, corresponding to `'b'`, it can be converted from `'z'` or `'a'`,
therefore:
  **`f(i, 1) = f(i−1, 25) + f(i−1, 0)`**

- If `c ≥ 2`, it can come from the last character conversion, therefore:
  **`f(i, c) = f(i−1, c−1)`**

---

### Optimization

Notice that in this recurrence formula, the calculation of `f(i, ⋯)` only
depends on the value of `f(i−1, ⋯)`. Therefore, we can use two one-dimensional
arrays instead of the entire two-dimensional array `f` for recursion, as can be
seen in the arrays `cnt` and `nxt` in the following code.

*/

class Solution {
public:
  int lengthAfterTransformations(string s, int t) {
    vector<int> cnt(26);
    for (char ch : s) {
      ++cnt[ch - 'a'];
    }
    for (int round = 0; round < t; ++round) {
      vector<int> nxt(26);
      nxt[0] = cnt[25];
      nxt[1] = (cnt[25] + cnt[0]) % mod;
      for (int i = 2; i < 26; ++i) {
        nxt[i] = cnt[i - 1];
      }
      cnt = move(nxt);
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      ans = (ans + cnt[i]) % mod;
    }
    return ans;
  }

private:
  static constexpr int mod = 1000000007;
};
// sub:
// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/submissions/1632457756/?envType=daily-question&envId=2025-05-13
