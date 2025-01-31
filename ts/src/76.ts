// 827. Making A Large Island

function largestIsland(grid: number[][]): number {
  const n = grid.length;
  const d = [1, 0, -1, 0, 1]; // Direction vectors
  const key: number[] = []; // Store sizes of all islands
  let id = 2; // Island IDs start from 2

  // Depth-First Search to mark island and calculate its size
  function dfs(row: number, col: number, id: number): number {
    grid[row][col] = id; // Mark cell with island ID
    let cnt = 1; // Initialize size of the island

    for (let i = 0; i < 4; i++) {
      // Explore all 4 directions
      const nr = row + d[i];
      const nc = col + d[i + 1];

      if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] === 1) {
        cnt += dfs(nr, nc, id);
      }
    }

    return cnt; // Return the total size of the island
  }

  // Identify all islands and calculate their sizes
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] === 1) {
        key.push(dfs(i, j, id++));
      }
    }
  }

  if (key.length === 0) return 1; // Grid contains no land

  let ans = 1;

  // Check all water cells and calculate potential island size
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] === 0) {
        let cnt = 1;
        const visited = new Set<number>(); // Track visited islands

        // Add sizes of neighboring islands
        for (let k = 0; k < 4; k++) {
          const nr = i + d[k];
          const nc = j + d[k + 1];

          if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] > 1) {
            const islandID = grid[nr][nc] - 2;
            if (!visited.has(islandID)) {
              cnt += key[islandID];
              visited.add(islandID);
            }
          }
        }

        ans = Math.max(ans, cnt); // Update the largest possible island size
      }
    }
  }

  return ans === 1 ? n * n : ans; // Return result
}

// Example Usage:
console.log(
  largestIsland([
    [1, 0, 1],
    [0, 1, 0],
    [1, 0, 1],
  ]),
); // Output: 5
//sub: https://leetcode.com/problems/making-a-large-island/submissions/1526666193/?envType=daily-question&envId=2025-01-31
//sol: https://leetcode.com/problems/making-a-large-island/solutions/6353291/827-making-a-large-island-by-nalindalal2-t37u/
