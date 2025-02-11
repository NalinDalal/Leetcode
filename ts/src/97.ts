//994. Rotting Oranges
function orangesRotting(grid: number[][]): number {
  const rows = grid.length;
  const cols = grid[0].length;
  const directions = [
    [-1, 0],
    [1, 0],
    [0, -1],
    [0, 1],
  ];

  let queue: [number, number][] = [];
  let freshCount = 0;

  // Step 1: Find all rotten oranges and count fresh ones
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] === 2) {
        queue.push([r, c]);
      } else if (grid[r][c] === 1) {
        freshCount++;
      }
    }
  }

  // If there are no fresh oranges, return 0 (already all rotten)
  if (freshCount === 0) return 0;

  let minutes = 0;

  // Step 2: Perform BFS
  while (queue.length > 0 && freshCount > 0) {
    let size = queue.length;
    for (let i = 0; i < size; i++) {
      let [x, y] = queue.shift()!;

      for (let [dx, dy] of directions) {
        let nx = x + dx,
          ny = y + dy;

        if (
          nx >= 0 &&
          nx < rows &&
          ny >= 0 &&
          ny < cols &&
          grid[nx][ny] === 1
        ) {
          // Rotten the fresh orange
          grid[nx][ny] = 2;
          queue.push([nx, ny]);
          freshCount--;
        }
      }
    }
    minutes++;
  }

  // If there are still fresh oranges left, return -1
  return freshCount === 0 ? minutes : -1;
}

//sub: https://leetcode.com/problems/rotting-oranges/submissions/1539346727/
//sol: https://leetcode.com/problems/rotting-oranges/solutions/6408185/994-rotting-oranges-by-nalindalal2004-sn0v/
