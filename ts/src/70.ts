// 2658. Maximum Number of Fish in a Grid

function findMaxFish(grid: number[][]): number {
  const m = grid.length;
  const n = grid[0].length;
  let maxFish = 0;

  // Helper function for depth-first search
  const dfs = (row: number, col: number): number => {
    // Boundary check and water cell check
    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] === 0) {
      return 0;
    }

    // Catch fish in the current cell
    let fish = grid[row][col];
    grid[row][col] = 0; // Mark cell as visited (set to 0)

    // Explore all 4 adjacent cells (up, down, left, right)
    fish += dfs(row + 1, col);
    fish += dfs(row - 1, col);
    fish += dfs(row, col + 1);
    fish += dfs(row, col - 1);

    return fish;
  };

  // Iterate through the grid
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] > 0) {
        // Start DFS if the cell contains fish
        maxFish = Math.max(maxFish, dfs(i, j));
      }
    }
  }

  return maxFish;
}

//92%
//sub: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/submissions/1523260879/?envType=daily-question&envId=2025-01-28
//sol: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/solutions/6339886/2658-maximum-number-of-fish-in-a-grid-by-gvke/
