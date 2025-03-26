//2033. Minimum Operations to Make a Uni-Value Grid
function minOperations(grid: number[][], x: number): number {
  const flat: number[] = grid.flat().sort((a, b) => a - b);

  // Check if all elements have the same remainder when divided by x
  const remainder = flat[0] % x;
  for (const num of flat) {
    if (num % x !== remainder) return -1;
  }

  // Find median as target value
  const median = flat[Math.floor(flat.length / 2)];

  // Calculate minimum operations
  return flat.reduce((ops, num) => ops + Math.abs(num - median) / x, 0);
}

// Example Usage
console.log(
  minOperations(
    [
      [2, 4],
      [6, 8],
    ],
    2,
  ),
); // Output: 4
//sub: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/submissions/1586301311/?envType=daily-question&envId=2025-03-26
//sol: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/solutions/6579946/2033-minimum-operations-to-make-a-uni-va-yvuq/
