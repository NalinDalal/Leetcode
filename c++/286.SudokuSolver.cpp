/* 37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of
the grid. The '.' character indicates empty cells.



Example 1:
Input: board =
[["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]

Output: [["5","3","4","6","7","8","9","1","2"],
["6","7","2","1","9","5","3","4","8"],
["1","9","8","3","4","2","5","6","7"],
["8","5","9","7","6","1","4","2","3"],
["4","2","6","8","5","3","7","9","1"],
["7","1","3","9","2","4","8","5","6"],
["9","6","1","5","3","7","2","8","4"],
["2","8","7","4","1","9","6","3","5"],
["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown
below:

Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.*/

// each row has only 1 instance of 1-9
// each column also has same rules
// each sub-box of 3x3 must also jave 1-9 appear exactly once
class Solution {
public:
  void solveSudoku(vector<vector<char>>& board) { solve(board); }

private:
  bool solve(vector<vector<char>>& board) {
    // Traverse through each cell in the board
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          // Try placing digits 1-9
          for (char num = '1'; num <= '9'; ++num) {
            if (isValid(board, i, j, num)) {
              // Place the number on the board temporarily
              board[i][j] = num;

              // Recursively attempt to solve the board
              if (solve(board)) {
                return true;
              }

              // Backtrack if placing num leads to a dead end
              board[i][j] = '.';
            }
          }

          // If no valid number can be placed, backtrack
          return false;
        }
      }
    }

    // If all cells are filled, the board is solved
    return true;
  }

  bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    // Check row constraints
    for (int j = 0; j < 9; ++j) {
      if (board[row][j] == num) {
        return false;
      }
    }

    // Check column constraints
    for (int i = 0; i < 9; ++i) {
      if (board[i][col] == num) {
        return false;
      }
    }

    // Check 3x3 sub-box constraints
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
      for (int j = startCol; j < startCol + 3; ++j) {
        if (board[i][j] == num) {
          return false;
        }
      }
    }

    return true;
  }
};

// sub: https://leetcode.com/problems/sudoku-solver/submissions/1566040327/
// sol:
// https://leetcode.com/problems/sudoku-solver/solutions/6509428/37-sudoku-solver-by-nalindalal2004-u1kz/
