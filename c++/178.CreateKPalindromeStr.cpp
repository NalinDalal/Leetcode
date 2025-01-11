/* https://leetcode.com/problems/construct-k-palindrome-strings/description/

1400. Construct K Palindrome Strings

Given a string s and an integer k, return true if you can use all the characters
in s to construct k palindrome strings or false otherwise.


Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the
characters of s. Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate
string.


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= 105*/

// count s size, k size; if s<k return false
// Determine the number of characters with odd frequencies (let's call this
// oddCount Toggle the bit corresponding to each character in the bitmask. Use
// Integer.bitCount() to count the number of odd frequencies.
class Solution {
public:
  bool canConstruct(string s, int k) {
    if (s.length() < k)
      return false;
    if (s.length() == k)
      return true;

    int odd = 0;

    for (char chr : s)
      odd ^= (1 << (chr - 'a'));

    return __builtin_popcount(odd) <= k;
  }
};

// Time: O(n)
// Space: O(1)
// 100%
// sub:
// https://leetcode.com/problems/construct-k-palindrome-strings/submissions/1505329816/
// soln:
// https://leetcode.com/problems/construct-k-palindrome-strings/solutions/6266091/1400-construct-k-palindrome-strings100-b-l57i/
