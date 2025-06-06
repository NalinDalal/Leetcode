/* 2434. Using a Robot to Print the Lexicographically Smallest String
You are given a string s and a robot that currently holds an empty string t.
Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot
will append this character to the string t. Remove the last character of a
string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper.



Example 1:

Input: s = "zza"
Output: "azz"
Explanation: Let p denote the written string.
Initially p="", s="zza", t="".
Perform first operation three times p="", s="", t="zza".
Perform second operation three times p="azz", s="", t="".
Example 2:

Input: s = "bac"
Output: "abc"
Explanation: Let p denote the written string.
Perform first operation twice p="", s="c", t="ba".
Perform second operation twice p="ab", s="c", t="".
Perform first operation p="ab", s="", t="c".
Perform second operation p="abc", s="", t="".
Example 3:

Input: s = "bdda"
Output: "addb"
Explanation: Let p denote the written string.
Initially p="", s="bdda", t="".
Perform first operation four times p="", s="", t="bdda".
Perform second operation four times p="addb", s="", t="".


Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.

Hint 1
If there are some character “a” ’ s in the string, they can be written on paper
before anything else. Hint 2 Every character in the string before the last “a”
should be written in reversed order. Hint 3 After the robot writes every “a” on
paper, the same holds for other characters “b”, ”c”, …etc.
*/

// well intuition was to sort the strings and return it
// but seems like it's wrong
// okay so let's convert the problem into algo step by step

// Approach:
/* 1. initialise a empty string t
2. initialise empty string p
3. now do until s and t are empty
4. remove s[0], append to t
5. remove t[t.length()-1], append to p
6. return p
*/
class Solution {
public:
  string robotWithString(string s) {
    int n = s.size();
    string p, t;
    vector<char> minRight(n);

    // Build the minRight array to store the smallest char to the right of index
    // i (including i)
    minRight[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      minRight[i] = min(s[i], minRight[i + 1]);
    }

    for (int i = 0; i < n; ++i) {
      t.push_back(s[i]);

      // While t is not empty and the last char of t <= smallest upcoming char
      // in s
      while (!t.empty() && (i == n - 1 || t.back() <= minRight[i + 1])) {
        p.push_back(t.back());
        t.pop_back();
      }
    }

    return p;
  }
};
// sub:
// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/submissions/1655312643/?envType=daily-question&envId=2025-06-06
