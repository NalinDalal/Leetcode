/*1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these
characters a, b and c.


Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters
a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab",
"cabc" and "abc" (again).

Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters
a, b and c are "aaacb", "aacb" and "acb".

Example 3:
Input: s = "abc"
Output: 1


Constraints:
3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.*/

// generate all possible substring of s
// now check if substring has alleast one occurence of a,b,c{all 3 must
// be present}
// if then ans++

// Solution
/* 1. Use a hashmap or array to track the count of `a`, `b`, and `c` in the
current window.
2. Expand the right pointer (`r`) to include characters until all three (`a`,
`b`, `c`) are present in the window.
3. Once all are found, increment the left pointer (`l`) while maintaining a
valid substring.
4. For every valid window found, add `(s.length() - r)` to the result because
every substring starting from `l` and ending at `r` to `s.length()-1` is valid.
    */
class Solution {
public:
  int numberOfSubstrings(string s) {
    int count[3] = {0, 0, 0}; // Track frequency of 'a', 'b', 'c'
    int l = 0, ans = 0;
    for (int r = 0; r < s.size(); ++r) {
      count[s[r] - 'a']++; // Increment the count of current character

      // Shrink the left pointer while all 'a', 'b', 'c' are present
      while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
        ans += s.size() - r; // All substrings starting from l to end are valid
        count[s[l] - 'a']--; // Remove leftmost character
        l++;                 // Move left pointer
      }
    }
    return ans;
  }
};
// Time: O(n)
// Space: O(1)

// sub:
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/1569765758/?envType=daily-question&envId=2025-03-11
// sol:
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/solutions/6522323/1358-number-of-substrings-containing-all-3j72/
