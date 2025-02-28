/*115. Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which
equals t. The test cases are generated so that the answer fits on a 32-bit
signed integer.



Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

Example 2:
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag


Constraints:
1 <= s.length, t.length <= 1000
s and t consist of English letters.*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    // given string s, find subsequences of s equal to t
    // return their number
    // create all possible subsequences of s
    // compare them with t, increase counter if equal
    // return counter
    int m = s.size();
    int n = t.size();
    const int MOD = 1e9 + 7;
    // dp[i][j] will store the number of distinct subsequences of s[0..i-1]
    // equal to t[0..j-1]
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

    // Initialize dp[i][0] to 1 because an empty t is a subsequence of any s
    for (int i = 0; i <= m; ++i) {
      dp[i][0] = 1;
    }

    // Fill the dp table
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        // If the characters match, we have two choices:
        // 1. Include the current character of s in the subsequence
        // 2. Do not include it
        if (s[i - 1] == t[j - 1]) {

          dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    // The result is stored in dp[m][n]
    return dp[m][n];
  }
};

// Time: O(m*n)
// Space: O(m*n)

// sub:
// https://leetcode.com/problems/distinct-subsequences/submissions/1557727924/
// sol:
// https://leetcode.com/problems/distinct-subsequences/solutions/6476059/115-distinct-subsequences-by-nalindalal2-8ksp/
