// 120. Triangle
//https://leetcode.com/problems/triangle/description/?envType=study-plan-v2&envId=top-interview-150

function minimumTotal(triangle: number[][]): number {
  let n: number = triangle.length;
  let dp: number[] = triangle[n - 1].slice(); // Start with the last row of the triangle

  // Start from the second last row and move upwards
  for (let row: number = n - 2; row >= 0; --row) {
    for (let col: number = 0; col <= row; ++col) {
      // Update DP value as the current value + min of two adjacent values below
      dp[col] = triangle[row][col] + Math.min(dp[col], dp[col + 1]);
    }
  }

  // The top element of DP array will have the minimum path sum
  return dp[0];
}

// https://leetcode.com/problems/triangle/submissions/1498324679/?envType=study-plan-v2&envId=top-interview-150
