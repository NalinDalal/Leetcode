/*1957. Delete Characters to Make Fancy String

A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to
make it fancy.

Return the final string after the deletion. It can be shown that the answer will
always be unique.



Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".


Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.

Hint 1
What's the optimal way to delete characters if three or more consecutive
characters are equal? Hint 2 If three or more consecutive characters are equal,
keep two of them and delete the rest.
*/

// so basically a sliding window of size of 3
// if all 3 are equal delete the first, move window by one
// once the last index is reached, break
// return the string

class Solution {
public:
  string makeFancyString(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
      if (i == s.size() - 1 || s[i] != s[i + 1] || s[i] != s[i + 2])
        ans += s[i];
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/submissions/1705461161/?envType=daily-question&envId=2025-07-21
// sol:
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/solutions/6984194/1957-delete-characters-to-make-fancy-str-jh4p/
