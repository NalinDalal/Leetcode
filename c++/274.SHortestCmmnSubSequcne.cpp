/*1092. Shortest Common Supersequence
Given two strings str1 and str2, return the shortest string that has both str1
and str2 as subsequences. If there are multiple valid strings, return any of
them.

A string s is a subsequence of string t if deleting some number of characters
from t (possibly 0) results in the string s.

Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

Example 2:
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"


Constraints:
1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
  string shortestCommonSupersequence(string a, string b) {
    int dp[1001][1001] = {}, m = a.size(), n = b.size();
    string res;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        dp[i + 1][j + 1] =
            a[i] == b[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
    while (m && n)
      res += dp[m][n] == dp[m - 1][n]   ? a[--m]
             : dp[m][n] == dp[m][n - 1] ? b[--n]
                                        : min(a[--m], b[--n]);
    return a.substr(0, m) + b.substr(0, n) + string(rbegin(res), rend(res));
  }
};

// sub:
// https://leetcode.com/problems/shortest-common-supersequence/submissions/1557740556/?envType=daily-question&envId=2025-02-28
// sol:
// https://leetcode.com/problems/shortest-common-supersequence/solutions/6476094/1092-shortest-common-supersequence-by-na-tt01/
