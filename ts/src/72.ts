//289. Game of Life
function gameOfLife(board: number[][]): void {
  const m = board.length,
    n = board[0].length;
  const temp = board.map((row) => [...row]);

  const dx = [-1, -1, -1, 0, 0, 1, 1, 1];
  const dy = [-1, 0, 1, -1, 1, -1, 0, 1];

  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      let liveNeighbors = 0;
      for (let k = 0; k < 8; k++) {
        const ni = i + dx[k],
          nj = j + dy[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && temp[ni][nj] === 1) {
          liveNeighbors++;
        }
      }

      if (board[i][j] === 1) {
        if (liveNeighbors < 2 || liveNeighbors > 3) {
          board[i][j] = 0; // Dies
        }
      } else {
        if (liveNeighbors === 3) {
          board[i][j] = 1; // Becomes alive
        }
      }
    }
  }
}
//100%
//sub: https://leetcode.com/problems/game-of-life/submissions/1524153272/
//sol: https://leetcode.com/problems/game-of-life/solutions/6343466/289-game-of-life100-by-nalindalal2004-u5mk/
