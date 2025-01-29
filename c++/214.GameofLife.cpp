/* https://leetcode.com/problems/game-of-life/description/
289. Game of Life

According to Wikipedia's article: "The Game of Life, also known simply as Life,
is a cellular automaton devised by the British mathematician John Horton Conway
in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial
state: live (represented by a 1) or dead (represented by a 0). Each cell
interacts with its eight neighbors (horizontal, vertical, diagonal) using the
following four rules (taken from the above Wikipedia article):

- Any live cell with fewer than two live neighbors dies as if caused by
under-population.
- Any live cell with two or three live neighbors lives on to the next
generation.
- Any live cell with more than three live neighbors dies, as if by
over-population.
- Any dead cell with exactly three live neighbors becomes a live cell, as if by
reproduction.

The next state of the board is determined by applying the above rules
simultaneously to every cell in the current state of the m x n grid board. In
this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next
state.

Note that you do not need to return anything.



Example 1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]


Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.


Follow up:
Could you solve it in-place? Remember that the board needs to be updated
simultaneously: You cannot update some cells first and then use their updated
values to update other cells. In this question, we represent the board using a
2D array. In principle, the board is infinite, which would cause problems when
the active area encroaches upon the border of the array (i.e., live cells reach
the border). How would you address these problems?
*/

class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    // update each cell inplace as per the rules:

    // 1. Any live cell with fewer than two live neighbors dies as if caused
    // by under-population.
    // 2.Any live cell with two or three live neighbors lives on to the next
    // generation. 3.Any live cell with more than three live neighbors dies,
    // as if by over-population. 4.Any dead cell with exactly three live
    // neighbors becomes a live cell, as if by reproduction.
    int m = board.size(), n = board[0].size();
    std::vector<std::vector<int>> temp = board;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int liveNeighbors = 0;
        for (int k = 0; k < 8; k++) {
          int ni = i + dx[k], nj = j + dy[k];
          if (ni >= 0 && ni < m && nj >= 0 && nj < n && temp[ni][nj] == 1) {
            liveNeighbors++;
          }
        }

        if (board[i][j] == 1) {
          if (liveNeighbors < 2 || liveNeighbors > 3) {
            board[i][j] = 0; // Dies
          }
        } else {
          if (liveNeighbors == 3) {
            board[i][j] = 1; // Becomes alive
          }
        }
      }
    }
  }
};
// 100%
// sub: https://leetcode.com/problems/game-of-life/submissions/1524150653/
// sol:
// https://leetcode.com/problems/game-of-life/solutions/6343466/289-game-of-life100-by-nalindalal2004-u5mk/
