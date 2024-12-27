/* 1014. Best Sightseeing Pair

You are given an integer array values where values[i] represents the value of
the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i
between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i -
j: the sum of the values of the sightseeing spots, minus the distance between
them.

Return the maximum score of a pair of sightseeing spots.



Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
Example 2:

Input: values = [1,2]
Output: 2


Constraints:

2 <= values.length <= 5 * 104
1 <= values[i] <= 1000
*/

#include <vector>
class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    // values[i]->ith element of array
    int n = values.size();
    // dp[i][j] is max score of pair(i,j)
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          dp[i][j] = values[i];
        else if (i < j)
          dp[i][j] = values[i] + values[j] + i - j;
        else
          dp[i][j] = dp[j][i];
      }
    }
    return dp[0][n - 1];
  }
};

// Issues:
/* Inefficient Approach: The dp matrix calculates scores for all possible pairs
(i, j), leading to 𝑂(𝑛^2) time complexity. This is unnecessary since the problem
can be solved in 𝑂(𝑛). Incorrect Return Value: The function returns dp[0][n-1],
but the maximum score does not necessarily involve the first and last elements.
Space Complexity: The use of a dp matrix results in 𝑂(𝑛^2) space, which is
suboptimal.*/

// Optimised:
// 29.83%
class Solution1 {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int maxScore = 0;
    int maxI = values[0]; // Maximum values[i] + i encountered so far

    for (int j = 1; j < values.size(); j++) {
      // Calculate score for the pair (i, j)
      maxScore = max(maxScore, maxI + values[j] - j);
      // Update maxI for the next iteration
      maxI = max(maxI, values[j] + j);
    }

    return maxScore;
  }
};

// 100%->
class Solution2 {
public:
  int maxScoreSightseeingPair(vector<int>& values) {

    int ans = 0;
    int a = values[0];
    for (int i = 1; i < values.size(); i++) {
      a--;
      int b = values[i];
      ans = max(ans, a + b);
      a = max(a, b);
    }
    return ans;
  }
};

/* Initialization:
maxI represents the best value of values[i]+i seen so far.
Start with values[0] + 0.

Iterate and Update:
For each j, calculate the score as `values[j]−j+maxI`.
Update maxI to include the current element j: maxI=max(maxI,values[j]+j).

Return Result:
The maxScore holds the maximum sightseeing score.*/
// 8 1 5 2 6
// (8) => (7)(1) => (6)(5) => (5)(2) =>

// Time : O(n)
// Space: O(1)
