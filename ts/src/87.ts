//52. N-Queens II

function totalNQueens(n: number): number {
  if (n === 1) return 1;

  let count = 0;
  const cols: boolean[] = new Array(n).fill(false); // Track columns with queens
  const diag1: boolean[] = new Array(2 * n - 1).fill(false); // Track \ diagonals
  const diag2: boolean[] = new Array(2 * n - 1).fill(false); // Track / diagonals

  function backtrack(row: number): void {
    if (row === n) {
      count++; // Found a valid configuration
      return;
    }

    for (let col = 0; col < n; col++) {
      if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) continue; // Conflict detected, skip

      // Place the queen
      cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

      // Recurse for the next row
      backtrack(row + 1);

      // Backtrack: Remove the queen
      cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
    }
  }

  backtrack(0);
  return count;
}

//sub: https://leetcode.com/problems/n-queens-ii/submissions/1533227701/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/n-queens-ii/solutions/6383320/52-n-queens-ii-by-nalindalal2004-xh4i/
