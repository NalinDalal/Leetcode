//37. Sudoku Solver

/**
 * Do not return anything, modify board in-place instead.
 */

function solveSudoku(board: string[][]): void {
  solve(board);
}

function solve(board: string[][]): boolean {
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      if (board[i][j] === ".") {
        for (let num = 1; num <= 9; num++) {
          if (isValid(board, i, j, num.toString())) {
            board[i][j] = num.toString();
            if (solve(board)) {
              return true;
            }
            board[i][j] = ".";
          }
        }
        return false;
      }
    }
  }
  return true;
}

function isValid(
  board: string[][],
  row: number,
  col: number,
  num: string,
): boolean {
  for (let i = 0; i < 9; i++) {
    if (board[i][col] === num) {
      return false;
    }
    if (board[row][i] === num) {
      return false;
    }
    if (
      board[3 * Math.floor(row / 3) + Math.floor(i / 3)][
        3 * Math.floor(col / 3) + (i % 3)
      ] === num
    ) {
      return false;
    }
  }
  return true;
}
//sub: https://leetcode.com/problems/sudoku-solver/submissions/1566046269/
//sol: https://leetcode.com/problems/sudoku-solver/solutions/6509428/37-sudoku-solver-by-nalindalal2004-u1kz/
