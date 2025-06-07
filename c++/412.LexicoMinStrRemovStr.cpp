/* 3170. Lexicographically Minimum String After Removing Stars
You are given a string s. It may contain any number of '*' characters. Your task
is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there
are several smallest characters, you can delete any of them. Return the
lexicographically smallest resulting string after removing all '*' characters.



Example 1:
Input: s = "aaba*"
Output: "aab"
Explanation:
We should delete one of the 'a' characters with '*'. If we choose s[3], s
becomes the lexicographically smallest.

Example 2:
Input: s = "abc"
Output: "abc"
Explanation:
There is no '*' in the string.



Constraints:
1 <= s.length <= 105
s consists only of lowercase English letters and '*'.
The input is generated such that it is possible to delete all '*' characters.
*/

/* algo:
1. build the string via a vector
2. iterate, if normal char push to stack, else If it's *, we find and remove the
smallest character in the stack
3. return string
             */

/* 1. Traverse the string `s` from left to right.

2. Use 26 stacks (one for each lowercase letter) to store indices of seen
characters.
   - For character `c`, push its index into `st[c - 'a']`.

3. When a `'*'` is encountered:
   - Find the **lexicographically smallest non-empty stack**.
   - Mark the character at the top index of that stack as `'*'` in `s`.
   - Pop that index from the stack.

4. Finally, construct the answer by including all characters in `s` that are
**not `'*'`**.
*/
class Solution {
public:
  string clearStars(string s) {
    vector<stack<int>> cnt(26);
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '*') {
        cnt[s[i] - 'a'].push(i);
      } else {
        for (int j = 0; j < 26; j++) {
          if (!cnt[j].empty()) {
            s[cnt[j].top()] = '*';
            cnt[j].pop();
            break;
          }
        }
      }
    }

    string ans;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '*') {
        ans.push_back(s[i]);
      }
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/submissions/1656201493/?envType=daily-question&envId=2025-06-07
