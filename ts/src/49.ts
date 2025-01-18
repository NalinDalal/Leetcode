//1368. Minimum Cost to Make at Least One Valid Path in a Grid
function minCost(grid: number[][]): number {
  const m = grid.length;
  const n = grid[0].length;

  // Directions: right, left, down, up
  const directions = [
    [0, 1], // right
    [0, -1], // left
    [1, 0], // down
    [-1, 0], // up
  ];

  const cost: number[][] = Array.from({ length: m }, () =>
    Array(n).fill(Infinity),
  );
  const deque: [number, number][] = [];

  deque.push([0, 0]);
  cost[0][0] = 0;

  while (deque.length > 0) {
    const [x, y] = deque.shift()!;

    for (let dir = 0; dir < 4; dir++) {
      const nx = x + directions[dir][0];
      const ny = y + directions[dir][1];

      if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
        // Calculate the cost for this move
        const newCost = cost[x][y] + (grid[x][y] === dir + 1 ? 0 : 1);

        if (newCost < cost[nx][ny]) {
          cost[nx][ny] = newCost;

          // Push to deque: 0 cost to the front, 1 cost to the back
          if (grid[x][y] === dir + 1) {
            deque.unshift([nx, ny]);
          } else {
            deque.push([nx, ny]);
          }
        }
      }
    }
  }

  return cost[m - 1][n - 1];
}
//sub: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/?envType=daily-question&envId=2025-01-18
//sol: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solutions/6298673/1368-minimum-cost-to-make-at-least-one-v-fv3k/
