// 417. Pacific Atlantic Water Flow

function pacificAtlantic(heights: number[][]): number[][] {
  const n = heights.length;
  const m = heights[0].length;

  // Initialize flag arrays to mark reachable cells for Pacific and Atlantic oceans
  const flag1: boolean[][] = Array.from({ length: n }, () =>
    Array(m).fill(false),
  );
  const flag2: boolean[][] = Array.from({ length: n }, () =>
    Array(m).fill(false),
  );
  const ans: number[][] = [];

  // Helper DFS function
  function dfs(
    grid: number[][],
    flag: boolean[][],
    x: number,
    y: number,
  ): void {
    flag[x][y] = true;

    // Directions for up, down, left, right
    const directions: [number, number][] = [
      [-1, 0], // Up
      [1, 0], // Down
      [0, -1], // Left
      [0, 1], // Right
    ];

    for (const [dx, dy] of directions) {
      const nx = x + dx;
      const ny = y + dy;

      if (
        nx >= 0 &&
        nx < n &&
        ny >= 0 &&
        ny < m &&
        !flag[nx][ny] &&
        grid[nx][ny] >= grid[x][y]
      ) {
        dfs(grid, flag, nx, ny);
      }
    }
  }

  // Pacific Ocean: DFS from top and left borders
  for (let i = 0; i < n; i++) {
    dfs(heights, flag1, i, 0); // Left edge
  }
  for (let i = 1; i < m; i++) {
    dfs(heights, flag1, 0, i); // Top edge
  }

  // Atlantic Ocean: DFS from bottom and right borders
  for (let i = 0; i < n; i++) {
    dfs(heights, flag2, i, m - 1); // Right edge
  }
  for (let i = 0; i < m - 1; i++) {
    dfs(heights, flag2, n - 1, i); // Bottom edge
  }

  // Collect coordinates that can flow to both Pacific and Atlantic
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (flag1[i][j] && flag2[i][j]) {
        ans.push([i, j]);
      }
    }
  }

  return ans;
}
