/* https://leetcode.com/problems/grid-game/description/?envType=daily-question&envId=2025-01-21

2017. Grid Game

You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c]
represents the number of points at position (r, c) on the matrix. Two robots are
playing a game on this matrix.

Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may
only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

At the start of the game, the first robot moves from (0, 0) to (1, n-1),
collecting all the points from the cells on its path. For all cells (r, c)
traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from
(0, 0) to (1, n-1), collecting the points on its path. Note that their paths may
intersect with one another.

The first robot wants to minimize the number of points collected by the second
robot. In contrast, the second robot wants to maximize the number of points it
collects. If both robots play optimally, return the number of points collected
by the second robot.



Example 1:

Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the
optimal path taken by the second robot is shown in blue. The cells visited by
the first robot are set to 0. The second robot will collect 0 + 0 + 4 + 0 = 4
points.

Example 2:

Input: grid = [[3,3,1],[8,5,2]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the
optimal path taken by the second robot is shown in blue. The cells visited by
the first robot are set to 0. The second robot will collect 0 + 3 + 1 + 0 = 4
points.

Example 3:

Input: grid = [[1,3,1,15],[1,3,3,1]]
Output: 7
Explanation: The optimal path taken by the first robot is shown in red, and the
optimal path taken by the second robot is shown in blue. The cells visited by
the first robot are set to 0. The second robot will collect 0 + 1 + 3 + 3 + 0 =
7 points.


Constraints:
grid.length == 2
n == grid[r].length
1 <= n <= 5 * 104
1 <= grid[r][c] <= 105*/

/*movement from (r,c) to (r+1,c) or (r,c+1) is allowed
1st robo moves from (0,0) to (1,n-1)
2nd moves from (0,0) to (1,n-1)
1st minimise 2nd
2nd maximise itself
return num of points collected by 2nd*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  long long gridGame(vector<vector<int>>& grid) {
    // n choices when moving to next row
    // use prefix sums
    int n = grid[0].size();
    vector<long long> topPrefix(n + 1, 0), bottomPrefix(n + 1, 0);

    // Compute prefix sums for both rows
    for (int i = 0; i < n; i++) {
      topPrefix[i + 1] = topPrefix[i] + grid[0][i];
      bottomPrefix[i + 1] = bottomPrefix[i] + grid[1][i];
    }

    long long result = LLONG_MAX;

    // Evaluate the maximum score Robot 2 can achieve for each split
    for (int i = 0; i < n; i++) {
      // Top row (Robot 2 moves down from i+1 to n-1)
      long long topRemaining = topPrefix[n] - topPrefix[i + 1];
      // Bottom row (Robot 2 moves from 0 to i-1)
      long long bottomRemaining = bottomPrefix[i];

      // Robot 2 will take the max of the two paths
      long long robot2Score = max(topRemaining, bottomRemaining);

      // Robot 1 minimizes the maximum score Robot 2 can achieve
      result = min(result, robot2Score);
    }

    return result;
  }
};
// avoid creating separate prefix arrays by directly calculating the prefix sums
// on-the-fly
class Solution2 {
public:
  long long gridGame(vector<vector<int>>& grid) {
    int n = grid[0].size();
    long long topSum = accumulate(grid[0].begin(), grid[0].end(),
                                  0LL); // Total sum of the top row
    long long bottomSum =
        0; // Initial sum of the bottom row (Robot 2 starts at 0)
    long long result = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
      // Robot 1 decides to move down after column `i`
      topSum -=
          grid[0]
              [i]; // Subtract current element from top row (prefix sum right)
      result =
          min(result, max(topSum, bottomSum)); // Max score Robot 2 can achieve
      bottomSum +=
          grid[1][i]; // Add current element to bottom row (prefix sum left)
    }

    return result;
  }
};
// Time: O(n)
// Space: O(1)
//  sub:
//  https://leetcode.com/problems/grid-game/submissions/1515777084/?envType=daily-question&envId=2025-01-21
//  sol:
//  https://leetcode.com/problems/grid-game/solutions/6311197/2017-grid-game100-by-nalindalal2004-9f0v/
