// https://leetcode.com/problems/spiral-matrix/
// 54. Spiral Matrix

function spiralOrder(matrix: number[][]): number[] {
  const result: number[] = [];
  if (matrix.length === 0) return result;

  let top = 0,
    bottom = matrix.length - 1;
  let left = 0,
    right = matrix[0].length - 1;

  while (top <= bottom && left <= right) {
    // Traverse from left to right along the top row
    for (let i = left; i <= right; i++) {
      result.push(matrix[top][i]);
    }
    top++;

    // Traverse from top to bottom along the right column
    for (let i = top; i <= bottom; i++) {
      result.push(matrix[i][right]);
    }
    right--;

    if (top <= bottom) {
      // Traverse from right to left along the bottom row
      for (let i = right; i >= left; i--) {
        result.push(matrix[bottom][i]);
      }
      bottom--;
    }

    if (left <= right) {
      // Traverse from bottom to top along the left column
      for (let i = bottom; i >= top; i--) {
        result.push(matrix[i][left]);
      }
      left++;
    }
  }

  return result;
}
// sub: https://leetcode.com/problems/spiral-matrix/submissions/1516907174/
// sol: https://leetcode.com/problems/spiral-matrix/solutions/6315491/54-spiral-matrix100-by-nalindalal2004-gv2a/
