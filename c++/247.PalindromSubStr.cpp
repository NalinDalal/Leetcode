/* 647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

    Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.*/

/* aim: return count of palindromic SubStr of s
- what if we have a string of length 1->count = 1;

to check palindromic substr of s
Expand around center while palindrome condition holds
if found palindrom expand around left and right

return count*/
class Solution {
public:
  int countSubstrings(string s) {
    // return count of palindromic SubStr of s
    int count = 0;
    // what if we have a string of length 1->count = 1;
    if (s.length() == 1)
      return 1;
    // to check palindromic substr of s
    // Expand around center
    for (int center = 0; center < 2 * s.length() - 1; ++center) {
      int left = center / 2;
      int right = left + (center % 2);

      // Expand while palindrome condition holds
      while (left >= 0 && right < s.length() && s[left] == s[right]) {
        count++; // Found a palindrome
        left--;  // Expand left
        right++; // Expand right
      }
    }

    return count;
  }
};
// Time: O(n^2)
// Space: O(1)

// sub:
// https://leetcode.com/problems/palindromic-substrings/submissions/1543411005/
// sol:
// https://leetcode.com/problems/palindromic-substrings/solutions/6423624/647-palindromic-substrings-by-nalindalal-pzy6/
