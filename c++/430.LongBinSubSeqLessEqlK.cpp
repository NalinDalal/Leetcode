/* 2311. Longest Binary Subsequence Less Than or Equal to K
You are given a binary string s and a positive integer k.

Return the length of the longest subsequence of s that makes up a binary number
less than or equal to k.

Note:

The subsequence can contain leading zeroes.
The empty string is considered to be equal to 0.
A subsequence is a string that can be derived from another string by deleting
some or no characters without changing the order of the remaining characters.


Example 1:

Input: s = "1001010", k = 5
Output: 5
Explanation: The longest subsequence of s that makes up a binary number less
than or equal to 5 is "00010", as this number is equal to 2 in decimal. Note
that "00100" and "00101" are also possible, which are equal to 4 and 5 in
decimal, respectively. The length of this subsequence is 5, so 5 is returned.
Example 2:

Input: s = "00101001", k = 1
Output: 6
Explanation: "000001" is the longest subsequence of s that makes up a binary
number less than or equal to 1, as this number is equal to 1 in decimal. The
length of this subsequence is 6, so 6 is returned.


Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.
1 <= k <= 109

Hint 1
Choosing a subsequence from the string is equivalent to deleting all the other
digits. Hint 2 If you were to remove a digit, which one should you remove to
reduce the value of the string?
*/

// so find which part(subsequence) of string represent no so that no<=k
// then maximise length of that part
// return length
/*
1. **Zeroes are Safe & Beneficial:**
   `'0'` adds **no value** to the binary number, so we can include **all
`'0'`s** without worrying about exceeding `k`.

2. **Why Zeroes Don’t Harm Value:**
   Adding a `'0'` shifts all bits left (doubles the value), but since `'0'`
itself adds nothing, we can **always remove a higher `'1'`** if value exceeds
`k`, keeping the **length same or better**.

3. **Greedily Add 1s from LSB:**
   Starting from the **least significant side (right)**, try to include `'1'`s
only if their **cumulative binary contribution stays ≤ `k`**. This ensures we
respect the constraint.

4. **Power Position Matters:**
   Every bit we add increases the **power** (bit position). Stop adding further
once the power is too high (e.g., `2^power > k`), as it **can’t possibly stay
within `k`**.

5. **Total Length = All Safe 0s + Valid 1s:**
   Count of subsequence = **all 0s** + **number of 1s we could include** within
the binary value limit — that gives the **maximum valid length**.


*/
class Solution {
public:
  int longestSubsequence(string s, int k) {
    int sm = 0;
    int cnt = 0;
    int bits = 32 - __builtin_clz(k);
    for (int i = 0; i < s.size(); ++i) {
      char ch = s[s.size() - 1 - i];
      if (ch == '1') {
        if (i < bits && sm + (1 << i) <= k) {
          sm += 1 << i;
          cnt++;
        }
      } else {
        cnt++;
      }
    }
    return cnt;
  }
};
// Time: O(n)
// Space: O(1)
// sub:
// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/submissions/1676928888/?envType=daily-question&envId=2025-06-26
// sol:
// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/solutions/6887180/2311-longest-binary-subsequence-less-tha-ornk/
