//130. Surrounded Regions
function solve(board: string[][]): void {
  const m = board.length;
  if (m === 0) return;
  const n = board[0].length;

  // Helper function for DFS traversal
  function dfs(i: number, j: number): void {
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] !== "O") return;

    board[i][j] = "#"; // Mark as visited

    // Explore 4 directions (up, down, left, right)
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
  }

  // Step 1: Mark all border-connected 'O' cells
  for (let i = 0; i < m; i++) {
    if (board[i][0] === "O") dfs(i, 0); // Left border
    if (board[i][n - 1] === "O") dfs(i, n - 1); // Right border
  }
  for (let j = 0; j < n; j++) {
    if (board[0][j] === "O") dfs(0, j); // Top border
    if (board[m - 1][j] === "O") dfs(m - 1, j); // Bottom border
  }

  // Step 2: Convert all remaining 'O' to 'X', and restore '#' to 'O'
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (board[i][j] === "O") {
        board[i][j] = "X"; // Surrounded 'O' -> 'X'
      } else if (board[i][j] === "#") {
        board[i][j] = "O"; // Restore unflipped 'O'
      }
    }
  }
}
//sub: https://leetcode.com/problems/surrounded-regions/submissions/1538145528/
//sol: https://leetcode.com/problems/surrounded-regions/solutions/6403092/130-surrounded-regions-by-nalindalal2004-1yim/
