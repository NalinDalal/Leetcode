/* 64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left
to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12


Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/

// move only down or right
// find min sum of path
// screames out classic dp

// Approach
/* use a 2D DP table where dp[i][j] represents the minimum sum to reach cell (i,
 * j). For each cell, we compute the min of the top and left neighbor plus the
 * cell’s value. Edges are initialized carefully since they can only be reached
 * from one direction.*/

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};
// Time: O(m*n)
// Space: O(m*n)
// Sub: https://leetcode.com/problems/minimum-path-sum/submissions/1603221044/
// sol:
// https://leetcode.com/problems/minimum-path-sum/solutions/6638112/64-minimum-path-sum-by-nalindalal2004-4lup/
