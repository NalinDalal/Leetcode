//3195. Find the Minimum Area to Cover All Ones I
function minimumArea(grid: number[][]): number {
  let m: number = grid.length;
  let n: number = grid[0].length;

  let minRow = m,
    maxRow = -1;
  let minCol = n,
    maxCol = -1;

  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        minRow = Math.min(minRow, i);
        maxRow = Math.max(maxRow, i);
        minCol = Math.min(minCol, j);
        maxCol = Math.max(maxCol, j);
      }
    }
  }

  let height = maxRow - minRow + 1;
  let width = maxCol - minCol + 1;
  return height * width;
}
//sub: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/submissions/1743816122/?envType=daily-question&envId=2025-08-22
//sol: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/solutions/7108103/3195-find-the-minimum-area-to-cover-all-eqxuw/
