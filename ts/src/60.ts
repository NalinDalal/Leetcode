// https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23

function countServers(grid: number[][]): number {
  let m: number = grid.length,
    n: number = grid[0].length;

  // Initialize row and column counters
  let row: number[] = new Array(m).fill(0),
    col: number[] = new Array(n).fill(0);
  let cnt = 0;

  // Count the servers in each row and column
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j]) {
        cnt++;
        row[i]++;
        col[j]++;
      }
    }
  }

  // Subtract isolated servers that have no other servers in their row or column
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] && row[i] === 1 && col[j] === 1) {
        cnt--;
      }
    }
  }

  return cnt;
}

//sub: https://leetcode.com/problems/count-servers-that-communicate/submissions/1518038790/?envType=daily-question&envId=2025-01-23
//sol: https://leetcode.com/problems/count-servers-that-communicate/solutions/6320205/1267-count-servers-that-communicate100-b-mhqv/
