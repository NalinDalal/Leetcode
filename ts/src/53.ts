/* https://leetcode.com/problems/set-matrix-zeroes/description/
 * 73. Set Matrix Zeroes*/

/* m*n matrix
if matrix[i][j] is zero then set matrix[O][j] to matrix[i][0] zero and matrix[i][0] to matrix[0][j] zero

check if a row item is zero, 
check if a col item is zero 
if yes then set whole row to zero 
check for row with column combination and vice-versa

helper function for ist row and column*/

/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix: number[][]): void {
  const m = matrix.length;
  const n = matrix[0].length;

  // Flags to mark if the first row and first column should be zeroed
  let firstRowZero = false;
  let firstColZero = false;

  // Check if the first row has any zeros
  for (let j = 0; j < n; j++) {
    if (matrix[0][j] === 0) {
      firstRowZero = true;
      break;
    }
  }

  // Check if the first column has any zeros
  for (let i = 0; i < m; i++) {
    if (matrix[i][0] === 0) {
      firstColZero = true;
      break;
    }
  }

  // Use the first row and column to mark rows and columns to be zeroed
  for (let i = 1; i < m; i++) {
    for (let j = 1; j < n; j++) {
      if (matrix[i][j] === 0) {
        matrix[i][0] = 0; // Mark the row
        matrix[0][j] = 0; // Mark the column
      }
    }
  }

  // Zero out cells based on the markers in the first row and column
  for (let i = 1; i < m; i++) {
    for (let j = 1; j < n; j++) {
      if (matrix[i][0] === 0 || matrix[0][j] === 0) {
        matrix[i][j] = 0;
      }
    }
  }

  // Zero out the first row if needed
  if (firstRowZero) {
    for (let j = 0; j < n; j++) {
      matrix[0][j] = 0;
    }
  }

  // Zero out the first column if needed
  if (firstColZero) {
    for (let i = 0; i < m; i++) {
      matrix[i][0] = 0;
    }
  }
}

//sub: https://leetcode.com/problems/set-matrix-zeroes/submissions/1514426875/
//sol: https://leetcode.com/problems/set-matrix-zeroes/solutions/6305900/73-set-matrix-zeroes100-by-nalindalal200-srnc/
