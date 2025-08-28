//3446. Sort Matrix by Diagonals
function sortMatrix(grid: number[][]): number[][] {
  const m = grid.length,
    n = grid[0].length;
  const diag: Map<number, number[]> = new Map();

  // collect diagonals
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      const key = i - j;
      if (!diag.has(key)) diag.set(key, []);
      diag.get(key)!.push(grid[i][j]);
    }
  }

  // sort conditionally
  for (const [key, arr] of diag.entries()) {
    if (key >= 0) {
      arr.sort((a, b) => b - a); // non-increasing
    } else {
      arr.sort((a, b) => a - b); // non-decreasing
    }
  }

  // write back
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      const key = i - j;
      grid[i][j] = diag.get(key)!.shift()!;
    }
  }

  return grid;
}
//sub: https://leetcode.com/problems/sort-matrix-by-diagonals/submissions/1750973430/?envType=daily-question&envId=2025-08-28
//sol: https://leetcode.com/problems/sort-matrix-by-diagonals/solutions/7130153/3446-sort-matrix-by-diagonals-by-nalinda-mtm3/
