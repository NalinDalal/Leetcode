/* https://leetcode.com/problems/making-a-large-island/description/?envType=daily-question&envId=2025-01-31
827. Making A Large Island

You are given an n x n binary matrix grid. You are allowed to change at most one
0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.



Example 1:
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with
area = 3.

Example 2:
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with
area = 4.

Example 3:
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.


Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.*/

/*Intuition:
Tag Islands → DFS assigns IDs (2,3,4...) and tracks sizes in key[]
Check Flips → For each '0', sum unique neighbor island sizes using sign-flip
trick*/

/*Sign-Flip Trick
Step 1: Add neighbor island size → mark as negative (prevents re-counting)
Step 2: Reset signs → restore original values for next flip checks
```cpp
// During flip check:
cnt += key[id];
key[id] *= -1;   // Mark as used

// After calculation:
key[id] *= -1;   // Reset for next 0-check
```
*/

class Solution {
  int d[5] = {1, 0, -1, 0, 1}; // Direction vectors
  int n;

  // Depth-First Search to mark island and calculate its size
  int dfs(int row, int col, int id, vector<vector<int>>& grid) {
    grid[row][col] = id; // Mark cell with island ID
    int cnt = 1;         // Initialize size of the island

    for (int i = 0; i < 4; i++) { // Explore all 4 directions
      int nr = row + d[i];
      int nc = col + d[i + 1];

      if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1)
        cnt += dfs(nr, nc, id, grid);
    }

    return cnt; // Return the total size of the island
  }

public:
  int largestIsland(vector<vector<int>>& grid) {
    n = grid.size();
    vector<int> key; // Store sizes of all islands
    int id = 2;      // Island IDs start from 2

    // Identify all islands and calculate their sizes
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1)
          key.push_back(dfs(i, j, id++, grid));
      }
    }

    if (key.empty())
      return 1; // Grid contains no land

    int ans = 1;

    // Check all water cells and calculate potential island size
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          int cnt = 1;

          // Add sizes of neighboring islands
          for (int k = 0; k < 4; k++) {
            int nr = i + d[k];
            int nc = j + d[k + 1];

            if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] != 0 &&
                key[grid[nr][nc] - 2] > 0)
              cnt += key[grid[nr][nc] - 2],
                  key[grid[nr][nc] - 2] *= -1; // Mark island as visited
          }

          // Reset the sizes of marked islands
          for (int k = 0; k < 4; k++) {
            int nr = i + d[k];
            int nc = j + d[k + 1];

            if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] != 0 &&
                key[grid[nr][nc] - 2] < 0)
              key[grid[nr][nc] - 2] *= -1; // Unmark island
          }

          ans = max(ans, cnt); // Update the largest possible island size
        }
      }
    }

    return ans == 1 ? n * n : ans; // Return result
  }
};
// Time: O(n^2)
// Space: O(n)
// sub:
// https://leetcode.com/problems/making-a-large-island/submissions/1526663807/?envType=daily-question&envId=2025-01-31
// sol:
// https://leetcode.com/problems/making-a-large-island/solutions/6353291/827-making-a-large-island-by-nalindalal2-t37u/
