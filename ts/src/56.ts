// https://leetcode.com/problems/grid-game/description/?envType=daily-question&envId=2025-01-21
//2017. Grid Game

function gridGame(grid: number[][]): number {
  const n = grid[0].length;

  let topSum = grid[0].reduce((acc, val) => acc + val, 0); // Total sum of the top row
  let bottomSum = 0; // Initial sum of the bottom row (Robot 2 starts at 0)
  let result = Number.MAX_SAFE_INTEGER;

  for (let i = 0; i < n; i++) {
    // Robot 1 decides to move down after column `i`
    topSum -= grid[0][i]; // Subtract current element from the top row
    result = Math.min(result, Math.max(topSum, bottomSum)); // Maximize Robot 2's points, minimize result
    bottomSum += grid[1][i]; // Add current element to the bottom row
  }

  return result;
}

//sub: https://leetcode.com/problems/grid-game/submissions/1515781601/?envType=daily-question&envId=2025-01-21
//sol: https://leetcode.com/problems/grid-game/solutions/6311197/2017-grid-game100-by-nalindalal2004-9f0v/
