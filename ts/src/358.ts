//36. Valid Sudoku
function isValidSudoku(board: string[][]): boolean {
  // Initialize 9x9 arrays for rows, columns, and 3x3 grids
  const rowcase: number[][] = Array.from({ length: 9 }, () => Array(9).fill(0));
  const colcase: number[][] = Array.from({ length: 9 }, () => Array(9).fill(0));
  const gridcase: number[][] = Array.from({ length: 9 }, () =>
    Array(9).fill(0),
  );

  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      const char = board[i][j];
      if (char !== ".") {
        const number = parseInt(char, 10) - 1; // convert to 0-based index
        const k = Math.floor(i / 3) * 3 + Math.floor(j / 3); // grid index

        // Check for duplicates
        if (
          rowcase[i][number]++ ||
          colcase[j][number]++ ||
          gridcase[k][number]++
        ) {
          return false;
        }
      }
    }
  }

  return true;
}

//sub: https://leetcode.com/problems/valid-sudoku/submissions/1753048396/
//sol: https://leetcode.com/problems/valid-sudoku/solutions/5570731/36-valid-sudoku/?envType=daily-question&envId=2025-08-30
