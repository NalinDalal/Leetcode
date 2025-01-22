// https://leetcode.com/problems/map-of-highest-peak/description/?envType=daily-question&envId=2025-01-22
// 765. Map of Highest Peak

// const LAND = 0;
const WATER = 1;
const DIRS = [-1, 0, 0, -1, 0, 1, 1, 0];

function highestPeak(isWater: number[][]): number[][] {
  const Y = isWater.length;
  const X = isWater[0].length;

  // Initialize the height matrix with max height
  const height = createMatrix(Y, X, Y + X - 2);

  // Add all water cells to a queue.
  // Set the height of water to zero.
  let queue: number[] = [];
  for (let y = 0; y < Y; ++y) {
    for (let x = 0; x < X; ++x) {
      if (isWater[y][x] == WATER) {
        queue.push(y, x);
        height[y][x] = 0;
      }
    }
  }

  // BFS
  let curHeight = 0;
  do {
    ++curHeight;
    const nextQ: number[] = [];
    // For each cell in the queue
    for (let i = 0; i < queue.length; i += 2) {
      const y = queue[i];
      const x = queue[i + 1];
      // For each cell neighbor
      for (let j = 0; j < DIRS.length; j += 2) {
        const y2 = y + DIRS[j];
        const x2 = x + DIRS[j + 1];
        // If neighbor exists and has not been visited
        if (
          y2 >= 0 &&
          y2 < Y &&
          x2 >= 0 &&
          x2 < X &&
          height[y2][x2] > curHeight
        ) {
          // Set cell height and add to next queue
          height[y2][x2] = curHeight;
          nextQ.push(y2, x2);
        }
      }
    }
    // Update queue to next queue
    queue = nextQ;
  } while (queue.length > 0);

  return height;
}

function createMatrix<T>(M: number, N: number, value: T): T[][] {
  const matrix = new Array(M);
  for (let m = 0; m < M; ++m) {
    matrix[m] = new Array(N).fill(value);
  }
  return matrix;
}
//100%
//sub: https://leetcode.com/problems/map-of-highest-peak/submissions/1516948625/?envType=daily-question&envId=2025-01-22
//sol: https://leetcode.com/problems/map-of-highest-peak/solutions/6315649/1765-map-of-highest-peak8883-by-nalindal-2kbj/
