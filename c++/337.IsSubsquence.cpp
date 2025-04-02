/*392. Is Subsequence

Given two strings s and t, return true if s is a subsequence of t, or false
otherwise.

A subsequence of a string is a new string that is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (i.e., "ace" is a subsequence of
"abcde" while "aec" is not).



Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false


Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.


Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >=
109, and you want to check one by one to see if t has its subsequence. In this
scenario, how would you change your code?

*/

// so basically use two pointrs and check if chars are equal
// say if s[i]==t[i] then i++ for both s,t
// else if s[i]!=t[i] then for t->i++
// if s gets whole passed then return true
// else return false
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int i = 0, j = 0;

    while (i < s.size() && j < t.size()) {
      if (s[i] == t[j]) {
        i++; // Move pointer for `s`
      }
      j++; // Always move pointer for `t`
    }

    return i == s.size(); // If `s` is completely traversed, it is a subsequence
  }
};
// sub:
// https://leetcode.com/problems/is-subsequence/submissions/1594053856/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/is-subsequence/solutions/6606224/392-is-subsequence-by-nalindalal2004-egtt/
