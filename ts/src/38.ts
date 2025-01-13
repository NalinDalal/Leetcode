//https://leetcode.com/problems/max-area-of-island/description/
//695. Max Area of Island

function maxAreaOfIsland(grid: number[][]): number {
  let maxArea = 0;
  const rows = grid.length;
  const cols = grid[0].length;

  // DFS function
  const dfs = (i: number, j: number): number => {
    // Base cases: Out of bounds or cell is water/visited
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] === 0) {
      return 0;
    }

    // Mark the cell as visited
    grid[i][j] = 0;

    // Recursively compute area in 4 directions
    let area = 1;
    area += dfs(i + 1, j);
    area += dfs(i - 1, j);
    area += dfs(i, j + 1);
    area += dfs(i, j - 1);

    return area;
  };

  // Iterate through the grid
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (grid[i][j] === 1) {
        maxArea = Math.max(maxArea, dfs(i, j));
      }
    }
  }

  return maxArea;
}
// 74.31%
// sub: https://leetcode.com/problems/max-area-of-island/submissions/1507248926/
// sol: https://leetcode.com/problems/max-area-of-island/solutions/6273914/695-max-area-of-island6132-by-nalindalal-qdza/
