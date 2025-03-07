//37. Sudoku Solver
impl Solution {
    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        Solution::solve(board);
    }

    fn solve(board: &mut Vec<Vec<char>>) -> bool {
        for i in 0..9 {
            for j in 0..9 {
                if board[i][j] == '.' {
                    for num in '1'..='9' {
                        if Solution::is_valid(board, i, j, num) {
                            board[i][j] = num;

                            if Solution::solve(board) {
                                return true;
                            }

                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number found, backtrack
                }
            }
        }
        true
    }

    fn is_valid(board: &Vec<Vec<char>>, row: usize, col: usize, num: char) -> bool {
        for i in 0..9 {
            if board[row][i] == num || board[i][col] == num {
                return false;
            }
        }

        let start_row = (row / 3) * 3;
        let start_col = (col / 3) * 3;
        for i in 0..3 {
            for j in 0..3 {
                if board[start_row + i][start_col + j] == num {
                    return false;
                }
            }
        }
        true
    }
}
//sub: https://leetcode.com/problems/sudoku-solver/submissions/1566043005/
//sol: https://leetcode.com/problems/sudoku-solver/solutions/6509428/37-sudoku-solver-by-nalindalal2004-u1kz/
