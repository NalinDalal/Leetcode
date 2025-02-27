/*97. Interleaving String

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1
and s2.

An interleaving of two strings s and t is a configuration where s and t are
divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3
+ s3 + ... Note: a + b is the concatenation of strings a and b.



Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" =
"aadbbcbcac". Since s3 can be obtained by interleaving s1 and s2, we return
true.

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string
to obtain s3.

Example 3:
Input: s1 = "", s2 = "", s3 = ""
Output: true


Constraints:
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.


Follow up: Could you solve it using only O(s2.length) additional memory space?*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    // interleaving s1 and s2 to get s3
    // s1+s2=s3
    // so first we need to generate a new string based on rules of
    // interleaving
    // then check the s3 with new string char by char

    // can't do, order is not defined
    // task: whether s3 can be formed by interleaving s1 and s2
    int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
    if (n1 + n2 != n3)
      return false;
    if (n1 < n2)
      return isInterleave(s2, s1, s3);
    vector<bool> dp(n2 + 1, false);
    dp[0] = true;
    // 1. Fill in the first row of dp array, considering only the characters
    // from s1.
    // 2. Fill in the first column of dp array, considering only the characters
    // from s2.

    for (int j = 1; j <= n2; ++j) {
      dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
    }
    // 3. Loop through each possible (i, j) combination, starting from (1, 1).
    // 4. Update dp[i][j] based on the transition dp[i][j] = (dp[i-1][j] and
    // s1[i-1] == s3[i+j-1]) or (dp[i][j-1] and s2[j-1] == s3[i+j-1]).
    for (int i = 1; i <= n1; ++i) {
      dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
      for (int j = 1; j <= n2; ++j) {
        dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
      }
    }

    return dp[n2];
  }
};

// Time: O(n^2)
// Space: O(n)

// sub:
// https://leetcode.com/problems/interleaving-string/submissions/1556654703/
// sol:
// https://leetcode.com/problems/interleaving-string/solutions/6472507/97-interleaving-string-by-nalindalal2004-aqgb/
