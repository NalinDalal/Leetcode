/* 72. Edit Distance
Given two strings word1 and word2, return the minimum number of operations
required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int minDistance(string word1, string word2) {
    // minimum no of operation to convert word1 to word2
    // horse->ros
    // replace h with r
    // remove r
    // remove e
    // intention->execution
    // remove t
    // replace i with e
    // replace n with x
    // replace n with c
    // insert u
    // build a 2D matrix dp where dp[i][j] represents the minimum number of
    // operations required to transform the substring word1[0...i-1] into the
    // substring word2[0...j-1]. if(word1[i-1] == word2[j-1]){dp[i][j] =
    // dp[i-1][j-1]} else{dp[i][j]=min(dp[i-1][j-1] + 1,dp[i-1][j] +
    // 1,dp[i][j-1] + 1)}
    // - dp[i-1][j-1] + 1: replace the character at position i-1 in word1 with
    // the character at position j-1 in word2.
    //- dp[i-1][j] + 1: delete the character at position i-1 in word1.
    //- dp[i][j-1] + 1: insert the character at position j-1 in word2 into word1
    // at position i return dp[m][n]{m-word1.length,n-word2.length} base case:
    // dp[i][0]=i-> i deletion required for word1 to be empty dp[0][j]=j-> j
    // insertion required to convert empty str to word2
    const int m = word1.length(); // first word length
    const int n = word2.length(); // second word length
    // dp[i][j] := min # of operations to convert word1[0..i) to word2[0..j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      dp[i][0] = i;

    for (int j = 1; j <= n; ++j)
      dp[0][j] = j;

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (word1[i - 1] == word2[j - 1]) // same characters
          dp[i][j] = dp[i - 1][j - 1];    // no operation
        else
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
    // replace       //delete        //insert
    return dp[m][n];
  }
};
// Time: O(m*n)
// Space: O(m*n)

// Optimised:
class Solution1 {
public:
  int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    // To ensure m <= n, swap if necessary
    if (m > n) {
      swap(word1, word2);
      swap(m, n);
    }

    // Previous and current rows of the DP table
    vector<int> previous(n + 1); // DP[i-1][j]
    vector<int> current(n + 1);  // DP[i][j]

    // Initialize the first row (base case when word1 is empty)
    for (int j = 0; j <= n; ++j) {
      previous[j] = j;
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
      current[0] = i; // Base case when word2 is empty

      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          current[j] = previous[j - 1]; // No operation needed
        } else {
          current[j] = min({previous[j - 1], previous[j], current[j - 1]}) + 1;
        }
      }

      // Move current row to previous row for the next iteration
      swap(previous, current);
    }

    // The result is stored in the last element of the previous row
    return previous[n];
  }
};
// sub: https://leetcode.com/problems/edit-distance/submissions/1558687345/

// sol:
// https://leetcode.com/problems/edit-distance/solutions/6479233/72-edit-distance-by-nalindalal2004-9gef/
