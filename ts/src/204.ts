//85. Maximal Rectangle

function maximalRectangle(matrix: string[][]): number {
  if (matrix.length === 0 || matrix[0].length === 0) return 0;

  const n = matrix.length,
    m = matrix[0].length;
  const height = new Array(m).fill(0);
  let maxArea = 0;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      height[j] = matrix[i][j] === "1" ? height[j] + 1 : 0;
    }
    maxArea = Math.max(maxArea, largestRectangleArea(height));
  }

  return maxArea;
}

function largestRectangleArea(heights: number[]): number {
  const stack: number[] = [];
  let maxArea = 0;
  const extended = [...heights, 0]; // Sentinel 0

  for (let i = 0; i < extended.length; i++) {
    while (
      stack.length > 0 &&
      extended[i] < extended[stack[stack.length - 1]]
    ) {
      const h = extended[stack.pop()!];
      const w = stack.length === 0 ? i : i - stack[stack.length - 1] - 1;
      maxArea = Math.max(maxArea, h * w);
    }
    stack.push(i);
  }

  return maxArea;
}
//sub: https://leetcode.com/problems/maximal-rectangle/submissions/1597139409/
//sol: https://leetcode.com/problems/maximal-rectangle/solutions/6617188/85-maximal-rectangle-by-nalindalal2004-ahgo/
