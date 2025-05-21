//73. Set Matrix Zeroes
/* m*n matrix
if matrix[i][j] is zero then set matrix[0][i] to matrix[i][0] zero and matrix[i][0] to matrix[0]][j] zero


check if a row item is zero,
check if a col item is zero
if yes then set whole row to zero check for row with column combination and vice-versa

helper function for ist row and column*/

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let m = matrix.len();
        if m == 0 {
            return;
        }
        let n = matrix[0].len();

        let mut first_row_zero = false;
        let mut first_col_zero = false;

        // Check if the first row has any zeros
        for j in 0..n {
            if matrix[0][j] == 0 {
                first_row_zero = true;
                break;
            }
        }

        // Check if the first column has any zeros
        for i in 0..m {
            if matrix[i][0] == 0 {
                first_col_zero = true;
                break;
            }
        }

        // Use the first row and column to mark rows and columns to be zeroed
        for i in 1..m {
            for j in 1..n {
                if matrix[i][j] == 0 {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero out cells based on the markers
        for i in 1..m {
            for j in 1..n {
                if matrix[i][0] == 0 || matrix[0][j] == 0 {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if first_row_zero {
            for j in 0..n {
                matrix[0][j] = 0;
            }
        }

        // Zero out the first column if needed
        if first_col_zero {
            for i in 0..m {
                matrix[i][0] = 0;
            }
        }
    }
}

//sub: https://leetcode.com/problems/set-matrix-zeroes/submissions/1639888372/?envType=daily-question&envId=2025-05-21
