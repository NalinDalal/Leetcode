/*https://leetcode.com/problems/surrounded-regions/description/
130. Surrounded Regions

You are given an m x n matrix board containing letters 'X' and 'O', capture
regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region
with 'X' cells and none of the region cells are on the edge of the board. To
capture a surrounded region, replace all 'O's with 'X's in-place within the
original board. You do not need to return anything.



Example 1:
Input: board =
[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output:
[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation:In the above diagram, the bottom region is not captured because it
is on the edge of the board and cannot be surrounded.

Example 2:
Input: board = [["X"]]
Output: [["X"]]



Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

// traverse the board cell by cell
// check if cell is X or O
// if O, check if surreounded by X or not
// if surrounded, replace with X
// start with borders cells, put O to #{temporarily}
// flip all O to X
// convert all # to O
#include <vector>
using namespace std;

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int m = board.size();
    if (m == 0)
      return;
    int n = board[0].size();

    // Step 1: Mark border-connected 'O' cells using DFS
    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O')
        dfs(board, i, 0); // Left border
      if (board[i][n - 1] == 'O')
        dfs(board, i, n - 1); // Right border
    }
    for (int j = 0; j < n; j++) {
      if (board[0][j] == 'O')
        dfs(board, 0, j); // Top border
      if (board[m - 1][j] == 'O')
        dfs(board, m - 1, j); // Bottom border
    }

    // Step 2: Convert all remaining 'O' to 'X' (since they are surrounded)
    // Step 3: Convert all '#' back to 'O' (restore unflipped cells)
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X'; // Surrounded 'O' -> 'X'
        } else if (board[i][j] == '#') {
          board[i][j] = 'O'; // Restore border-connected 'O'
        }
      }
    }
  }

private:
  void dfs(vector<vector<char>>& board, int i, int j) {
    int m = board.size(), n = board[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
      return;

    board[i][j] = '#'; // Mark as visited

    // Move in 4 directions (up, down, left, right)
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
  }
};

// 100%
// sub: https://leetcode.com/problems/surrounded-regions/submissions/1538140262/
// sol:
// https://leetcode.com/problems/surrounded-regions/solutions/6403092/130-surrounded-regions-by-nalindalal2004-1yim/
