/* https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28
2658. Maximum Number of Fish in a Grid

You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations
any number of times: Catch all the fish at cell (r, c), or Move to any adjacent
water cell. Return the maximum number of fish the fisher can catch if he chooses
his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1),
(r + 1, c) or (r - 1, c) if it exists.

Example 1:
Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to
cell (2,3) and collect 4 fish.

Example 2:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single
fish.


Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
0 <= grid[i][j] <= 10
*/

#include <vector>
using namespace std;
class Solution {
public:
  int findMaxFish(vector<vector<int>>& grid) {
    // land cell =0
    // water cell >0
    // start at (r,c)
    // if(water){catch all fish}
    // else{move to adjacent cell}
    // repeat till no water cell exist
    // return max fish caught, so need to add it man,not take it's max
    int m = grid.size();
    int n = grid[0].size();
    int maxFish = 0;

    // Helper function for depth-first search
    auto dfs = [&](int row, int col, auto& dfsRef) -> int {
      // Boundary check and water cell check
      if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) {
        return 0;
      }

      // Catch fish in the current cell
      int fish = grid[row][col];
      grid[row][col] = 0; // Mark cell as visited (set to 0)

      // Explore all 4 adjacent cells (up, down, left, right)
      fish += dfsRef(row + 1, col, dfsRef);
      fish += dfsRef(row - 1, col, dfsRef);
      fish += dfsRef(row, col + 1, dfsRef);
      fish += dfsRef(row, col - 1, dfsRef);

      return fish;
    };

    // Iterate through the grid
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] > 0) { // Start DFS if the cell contains fish
          maxFish = std::max(maxFish, dfs(i, j, dfs));
        }
      }
    }

    return maxFish;
  }
};

// Time: O(m*n)
// Space:O(1)
// sub:
// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/submissions/1523257990/?envType=daily-question&envId=2025-01-28
// sol:
// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/solutions/6339886/2658-maximum-number-of-fish-in-a-grid-by-gvke/
