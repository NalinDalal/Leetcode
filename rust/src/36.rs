//36. Valid Sudoku
impl Solution{
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut rowcase = [[0; 9]; 9];
        let mut colcase = [[0; 9]; 9];
        let mut gridcase = [[0; 9]; 9];

        for i in 0..9 {
            for j in 0..9 {
                let c = board[i][j];
                if c != '.' {
                    let num = (c as u8 - b'1') as usize; // convert '1'-'9' to 0-8
                    let grid = (i / 3) * 3 + (j / 3);

                    if rowcase[i][num] > 0 || colcase[j][num] > 0 || gridcase[grid][num] > 0 {
                        return false;
                    }

                    rowcase[i][num] += 1;
                    colcase[j][num] += 1;
                    gridcase[grid][num] += 1;
                }
            }
        }

        true
    }
}
//sub: https://leetcode.com/problems/valid-sudoku/submissions/1753048692/
//sol: https://leetcode.com/problems/valid-sudoku/solutions/5570731/36-valid-sudoku/?envType=daily-question&envId=2025-08-30
