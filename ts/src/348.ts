//1277. Count Square Submatrices with All Ones
function countSquares(matrix: number[][]): number {
  const m = matrix.length;
  const n = matrix[0].length;
  const dp: number[][] = Array.from({ length: m }, () => Array(n).fill(0));
  let total = 0;

  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (matrix[i][j] === 1) {
        if (i === 0 || j === 0) {
          dp[i][j] = 1; // first row or col, only 1x1 squares
        } else {
          dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        }
        total += dp[i][j];
      }
    }
  }
  return total;
}
//sub: https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/1741545780/?envType=daily-question&envId=2025-08-20
//sol: https://leetcode.com/problems/count-square-submatrices-with-all-ones/solutions/7101654/1277-count-square-submatrices-with-all-o-t6k5/
