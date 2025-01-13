/* https://leetcode.com/problems/max-area-of-island/description/

695. Max Area of Island

You are given an m x n binary matrix grid. An island is a group of 1's
(representing land) connected 4-directionally (horizontal or vertical.) You may
assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.



Example 1:


Input: grid =
[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected
4-directionally. Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.*/

#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 1) {
          // check if island is connected 4-directionally
          // noob cause for each cell have to check if it is connected
          // or not
          int count = 0;
          if (i > 0) {
            if (grid[i - 1][j] == 1)
              count++;
          }
          // need to account for j also
          if (j > 0) {
            if (grid[i][j - 1] == 1)
              count++;
          }

          if (i < grid.size() - 1) {
            if (grid[i + 1][j] == 1) {
              count++;
            }
            if (j < grid[i].size() - 1) {
              if (grid[i][j + 1] == 1) {
                count++;
              }
            }
          }
          maxArea = max(maxArea, count);
        }
      }
    }
    return maxArea;
  }
};
// Time: O(m*n)
// Space: O(m*n)
//  better approach
/* Traverse the grid.
When a 1 is encountered, use DFS or BFS to compute the size of the connected
component. Track the maximum area encountered.*/

class Solution1 {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    // Lambda for DFS traversal
    function<int(int, int)> dfs = [&](int i, int j) {
      // Base cases: Out of bounds or cell is water/visited
      if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0)
        return 0;

      // Mark the cell as visited
      grid[i][j] = 0;

      // Recursively compute area in 4 directions
      int area = 1;
      area += dfs(i + 1, j);
      area += dfs(i - 1, j);
      area += dfs(i, j + 1);
      area += dfs(i, j - 1);

      return area;
    };

    // Iterate through the grid
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 1) {
          maxArea = max(maxArea, dfs(i, j));
        }
      }
    }

    return maxArea;
  }
};

// more efficient
// use an explicit stack to replace recursion, avoiding the overhead of function
// calls and reducing space usage
/* Create dfs:
If out of bounds or on water (0), return 0
If island (1) mark as visited by updating grid
Recursively explore neighbors and sum their areas, adding 1
Iterate through the grid:
Update max_area with the max island area found via dfs
Return max_area
             */
class Solution2 {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    // DFS function
    auto dfs = [&](int i, int j, auto&& dfs_ref) -> int {
      // Check for out of bounds or water
      if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0)
        return 0;

      // Mark the cell as visited
      grid[i][j] = 0;

      // Explore neighbors and sum their areas
      return 1 + dfs_ref(i + 1, j, dfs_ref) + dfs_ref(i - 1, j, dfs_ref) +
             dfs_ref(i, j + 1, dfs_ref) + dfs_ref(i, j - 1, dfs_ref);
    };

    // Iterate through the grid
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 1) {
          maxArea = max(maxArea, dfs(i, j, dfs));
        }
      }
    }

    return maxArea;
  }
};

// sub: https://leetcode.com/problems/max-area-of-island/submissions/1507240073/
// sol:
// https://leetcode.com/problems/max-area-of-island/solutions/6273914/695-max-area-of-island6132-by-nalindalal-qdza/
