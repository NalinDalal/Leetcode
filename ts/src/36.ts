//3417. Zigzag Grid Traversal With Skip

function zigzagTraversal(grid: number[][]): number[] {
  let result: number[] = [];
  let n = grid.length; // Number of rows
  if (n === 0) return result;
  let m = grid[0].length; // Number of columns

  for (let i = 0; i < n; ++i) {
    if (i % 2 === 0) {
      // Left to right
      for (let j = 0; j < m; ++j) {
        if (j % 2 === 0) {
          // Include only even-indexed cells
          result.push(grid[i][j]);
        }
      }
    } else {
      // Right to left
      for (let j = m - 1; j >= 0; --j) {
        if (j % 2 !== 0) {
          // Include only odd-indexed cells
          result.push(grid[i][j]);
        }
      }
    }
  }

  return result;
}

// sol: https://leetcode.com/problems/zigzag-grid-traversal-with-skip/solutions/6267543/3417-zigzag-grid-traversal-with-skip40-b-9vq0/
// sub: https://leetcode.com/problems/zigzag-grid-traversal-with-skip/submissions/1505790005/
