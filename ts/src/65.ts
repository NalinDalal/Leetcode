//329. Longest Increasing Path in a Matrix
function longestIncreasingPath(matrix: number[][]): number {
  const m = matrix.length;
  const n = matrix[0].length;

  // Direction vectors for moving up, down, left, and right
  const dir = [-1, 0, 1, 0, -1];

  // Step 1: Compute the indegree for each cell
  const indegree: number[][] = Array.from({ length: m }, () =>
    Array(n).fill(0),
  );
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      for (let k = 0; k < 4; k++) {
        const ni = i + dir[k];
        const nj = j + dir[k + 1];
        if (
          ni >= 0 &&
          nj >= 0 &&
          ni < m &&
          nj < n &&
          matrix[ni][nj] > matrix[i][j]
        ) {
          indegree[ni][nj]++;
        }
      }
    }
  }

  // Step 2: Add all cells with indegree 0 to the queue
  const queue: [number, number][] = [];
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (indegree[i][j] === 0) {
        queue.push([i, j]);
      }
    }
  }

  // Step 3: Perform BFS to find the longest path
  let maxLen = 0;
  while (queue.length > 0) {
    const size = queue.length;
    maxLen++; // Each BFS level corresponds to one step in the longest path
    for (let i = 0; i < size; i++) {
      const [x, y] = queue.shift()!;
      for (let k = 0; k < 4; k++) {
        const nx = x + dir[k];
        const ny = y + dir[k + 1];
        if (
          nx >= 0 &&
          ny >= 0 &&
          nx < m &&
          ny < n &&
          matrix[nx][ny] > matrix[x][y]
        ) {
          indegree[nx][ny]--;
          if (indegree[nx][ny] === 0) {
            queue.push([nx, ny]);
          }
        }
      }
    }
  }

  return maxLen;
}
//sub: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/1521201365/
//sol: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/solutions/6332134/329-longest-increasing-path-in-a-matrix7-xxj0/
