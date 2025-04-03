/*58. Length of Last Word

Given a string s consisting of words and spaces, return the length of the last
word in the string.

A word is a maximal substring consisting of non-space characters only.



Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.


Constraints:
1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

// well check for first letter appearance
// then check for next space appearance
// return the length b/w the two

class Solution {
public:
  int lengthOfLastWord(string s) {
    int length = 0;
    int i = s.size() - 1;

    // Ignore trailing spaces at the end
    while (i >= 0 && s[i] == ' ') {
      i--;
    }

    // Count the length of the last word
    while (i >= 0 && s[i] != ' ') {
      length++;
      i--;
    }

    return length;
  }
};
// sub:
// https://leetcode.com/problems/length-of-last-word/submissions/1595476599/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/length-of-last-word/solutions/6610941/58-length-of-last-word-by-nalindalal2004-yzbw/
