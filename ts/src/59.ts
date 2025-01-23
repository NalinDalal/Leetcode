//48. Rotate Image
/**
 Do not return anything, modify matrix in-place instead.
 */
function rotate(matrix: number[][]): void {
  const n = matrix.length;

  // Transpose the matrix
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      // Swap matrix[i][j] with matrix[j][i]
      [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
    }
  }

  // Reverse each row
  for (let i = 0; i < n; i++) {
    matrix[i].reverse();
  }
}

//sub: https://leetcode.com/problems/rotate-image/submissions/1518024587/
//sol: https://leetcode.com/problems/rotate-image/solutions/6320151/48-rotate-image100-by-nalindalal2004-dnq7/
