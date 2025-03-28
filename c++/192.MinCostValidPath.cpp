/* https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18

1368. Minimum Cost to Make at Least One Valid Path in a Grid

Given an m x n grid. Each cell of the grid has a sign pointing to the next cell
you should visit if you are currently in this cell. The sign of grid[i][j] can
be:

1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j
+ 1]) 2 which means go to the cell to the left. (i.e go from grid[i][j] to
grid[i][j - 1]) 3 which means go to the lower cell. (i.e go from grid[i][j] to
grid[i + 1][j]) 4 which means go to the upper cell. (i.e go from grid[i][j] to
grid[i - 1][j]) Notice that there could be some signs on the cells of the grid
that point outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid
is a path that starts from the upper left cell (0, 0) and ends at the
bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path
does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a
cell one time only.

Return the minimum cost to make the grid have at least one valid path.

Example 1:
Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change
the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0)
change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2,
3) change the arrow to down with cost = 1 --> (3, 3) The total cost = 3.

Example 2:
Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
Output: 0
Explanation: You can follow the path from (0, 0) to (2, 2).

Example 3:
Input: grid = [[1,2],[4,3]]
Output: 1


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
1 <= grid[i][j] <= 4*/
#include <deque>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

/* Use a deque to perform a BFS traversal.
Push nodes with cost 0 to the front of the deque if the arrow is followed.
Push nodes with cost 1 to the back of the deque if the arrow needs to be
changed.*/
class Solution {
public:
  int minCost(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
    deque<pair<int, int>> dq;

    // Directions: right, left, down, up
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    dq.push_back({0, 0});
    cost[0][0] = 0;

    while (!dq.empty()) {
      auto [x, y] = dq.front();
      dq.pop_front();

      for (int dir = 0; dir < 4; dir++) {
        int nx = x + directions[dir].first;
        int ny = y + directions[dir].second;
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          int newCost = cost[x][y] + (grid[x][y] != dir + 1 ? 1 : 0);
          if (newCost < cost[nx][ny]) {
            cost[nx][ny] = newCost;
            if (grid[x][y] != dir + 1) {
              dq.push_back({nx, ny});
            } else {
              dq.push_front({nx, ny});
            }
          }
        }
      }
    }

    return cost[m - 1][n - 1];
  }
};

// 96%
// Time: O(n*m)
// Space: O(n*m)
// sub:
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/submissions/1512464785/?envType=daily-question&envId=2025-01-18
// sol:
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solutions/6298673/1368-minimum-cost-to-make-at-least-one-v-fv3k/
