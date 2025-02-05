// 51. N-Queens
function solveNQueens(n: number): string[][] {
  const results: string[][] = [];
  const board: string[] = Array(n).fill(".".repeat(n));
  const cols: boolean[] = Array(n).fill(false);
  const diag1: boolean[] = Array(2 * n - 1).fill(false); // \ diagonals
  const diag2: boolean[] = Array(2 * n - 1).fill(false); // / diagonals

  backtrack(0, n, board, results, cols, diag1, diag2);
  return results;
}

function backtrack(
  row: number,
  n: number,
  board: string[],
  results: string[][],
  cols: boolean[],
  diag1: boolean[],
  diag2: boolean[],
): void {
  if (row === n) {
    results.push([...board]);
    return;
  }

  for (let col = 0; col < n; col++) {
    if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
      continue;
    }

    // Place the queen
    board[row] =
      board[row].substring(0, col) + "Q" + board[row].substring(col + 1);
    cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

    // Recurse for the next row
    backtrack(row + 1, n, board, results, cols, diag1, diag2);

    // Backtrack: Remove the queen
    board[row] =
      board[row].substring(0, col) + "." + board[row].substring(col + 1);
    cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
  }
}

let result4 = solveNQueens(4);
console.log(result4);

let result1 = solveNQueens(1);
console.log(result1);

//sub: https://leetcode.com/problems/n-queens/submissions/1532136417/
//sol: https://leetcode.com/problems/n-queens/solutions/6378828/51-n-queens-by-nalindalal2004-5zac/
