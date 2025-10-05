/* 417. Pacific Atlantic Water Flow

There is an m x n rectangular island that borders both the Pacific Ocean and
Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and
the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n
integer matrix heights where heights[r][c] represents the height above sea level
of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring
cells directly north, south, east, and west if the neighboring cell's height is
less than or equal to the current cell's height. Water can flow from any cell
adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes
that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic
oceans.



Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as
shown below: [0,4]: [0,4] -> Pacific Ocean [0,4] -> Atlantic Ocean [1,3]: [1,3]
-> [0,3] -> Pacific Ocean [1,3] -> [1,4] -> Atlantic Ocean [1,4]: [1,4] -> [1,3]
-> [0,3] -> Pacific Ocean [1,4] -> Atlantic Ocean [2,2]: [2,2] -> [1,2] -> [0,2]
-> Pacific Ocean [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean [3,0]: [3,0] ->
Pacific Ocean [3,0] -> [4,0] -> Atlantic Ocean [3,1]: [3,1] -> [3,0] -> Pacific
Ocean [3,1] -> [4,1] -> Atlantic Ocean [4,0]: [4,0] -> Pacific Ocean [4,0] ->
Atlantic Ocean Note that there are other possible paths for these cells to flow
to the Pacific and Atlantic oceans.


Example 2:
Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic
oceans.


Constraints:
m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105*/

#include <vector>
using std::vector;
class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ocean(heights.size());
    for (int i = 0; i < heights.size(); i++) {
      for (int j = 0; j < heights[i].size(); j++) {
        if (heights[i][j] <= 0) {
          ocean[i].push_back(j);
        }
      }
    }
    return ocean;
  }
};

/* Issues in the current code:
1. Incorrect Logic: The condition if (heights[i][j] <= 0) seems misplaced for
checking if a cell is reachable by either ocean. Instead, the problem typically
requires a flow simulation from the boundary cells (Pacific and Atlantic) to see
which cells can reach both oceans.

2. Ocean Matrix Construction: The ocean matrix is being filled incorrectly. You
likely want to track which cells can flow into the Pacific and Atlantic oceans,
not just store the column indices.

3. DFS or BFS Approach Missing: You need a method (usually DFS or BFS) to
simulate the flow from the ocean boundaries and mark the cells that can reach
each ocean.*/

/* Plan for Solution:
Pacific Ocean: The Pacific ocean is connected to the top and left edges.
Atlantic Ocean: The Atlantic ocean is connected to the bottom and right edges.
For each ocean, we'll use DFS or BFS to propagate from the boundaries and mark
reachable cells.*/

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (heights.empty() || heights[0].empty()) {
      return {};
    }

    int m = heights.size();
    int n = heights[0].size();

    // Two 2D boolean arrays to keep track of reachable cells for each ocean
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    // Define DFS function
    function<void(int, int, vector<vector<bool>>&)> dfs =
        [&](int i, int j, vector<vector<bool>>& ocean) {
          // Mark the current cell as reachable
          ocean[i][j] = true;

          // Directions for up, down, left, right movement
          vector<pair<int, int>> directions = {
              {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

          for (auto& dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;

            // Check if the new position is within bounds and the current cell
            // is less than or equal to the neighbor
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !ocean[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {
              dfs(ni, nj, ocean);
            }
          }
        };

    // Perform DFS from the boundaries
    for (int i = 0; i < m; ++i) {
      dfs(i, 0, pacific);      // Left edge (Pacific)
      dfs(i, n - 1, atlantic); // Right edge (Atlantic)
    }
    for (int j = 0; j < n; ++j) {
      dfs(0, j, pacific);      // Top edge (Pacific)
      dfs(m - 1, j, atlantic); // Bottom edge (Atlantic)
    }

    // The result will store the cells that can reach both oceans
    vector<vector<int>> result;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pacific[i][j] && atlantic[i][j]) {
          result.push_back({i, j});
        }
      }
    }

    return result;
  }
};

// Explanation:
/*1. DFS function: This is used to explore the grid starting from a given cell.
It marks cells as reachable if the cell's height is greater than or equal to the
current cell's height (this simulates the flow).

2. Initialization: We create two matrices pacific and atlantic to track whether
each cell can reach the Pacific or Atlantic ocean.

3. Boundary DFS Calls: We call DFS for each of the four borders (top, bottom,
left, right) to simulate the flow from both oceans.

4. Result Calculation: After the DFS, we check each cell. If a cell can reach
both the Pacific and Atlantic oceans, it's added to the result.*/

// Time Complexity: O(m*n)
// Space Complexity: O(m*n);m and n are grid dimensions

// more fast:
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>

class Solution1 {
public:
  int n, m;

  // Go througout the adjacent if the adjacent's height is more or equal to
  // current height
  void dfs(vvi& grid, vvb& flag, int x, int y) {
    flag[x][y] = true;
    if (x - 1 >= 0 && !flag[x - 1][y] && grid[x - 1][y] >= grid[x][y])
      dfs(grid, flag, x - 1, y);
    if (x + 1 < n && !flag[x + 1][y] && grid[x + 1][y] >= grid[x][y])
      dfs(grid, flag, x + 1, y);
    if (y - 1 >= 0 && !flag[x][y - 1] && grid[x][y - 1] >= grid[x][y])
      dfs(grid, flag, x, y - 1);
    if (y + 1 < m && !flag[x][y + 1] && grid[x][y + 1] >= grid[x][y])
      dfs(grid, flag, x, y + 1);
  }

  vvi pacificAtlantic(vvi& heights) {
    n = heights.size();
    m = heights[0].size();

    vvb flag1(n, vb(m)), flag2(n, vb(m));
    vvi ans;

    // Pacific
    // Do DFS starting from upper border and left border
    // Mark true in flag1 if posibble
    for (int i = 0; i < n; i++)
      dfs(heights, flag1, i, 0);
    for (int i = 1; i < m; i++)
      dfs(heights, flag1, 0, i);

    // Attlantic
    // DFS starting from bottom border and right border
    // Mark true in flag2 if posibble
    for (int i = 0; i < n; i++)
      dfs(heights, flag2, i, m - 1);
    for (int i = 0; i < m - 1; i++)
      dfs(heights, flag2, n - 1, i);

    // Add cordinate to ans if both flag1 and flag2 is equal to true
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (flag1[i][j] && flag2[i][j])
          ans.push_back({i, j});

    return ans;
  }
};
// sub:
// https://leetcode.com/problems/pacific-atlantic-water-flow/submissions/1495823715/?envType=daily-question&envId=2025-10-05
// sol:
// https://leetcode.com/problems/pacific-atlantic-water-flow/solutions/7250636/417-pacific-atlantic-water-flow-by-nalin-rn3z/
