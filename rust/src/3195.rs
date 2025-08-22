//3195. Find the Minimum Area to Cover All Ones I
impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let mut min_row: Option<usize> = None;
        let mut min_col: Option<usize> = None;
        let mut max_row: usize = 0;
        let mut max_col: usize = 0;

        for (i, row) in grid.iter().enumerate() {
            for (j, &val) in row.iter().enumerate() {
                if val == 1 {
                    min_row = Some(min_row.map_or(i, |r| r.min(i)));
                    max_row = max_row.max(i);
                    min_col = Some(min_col.map_or(j, |c| c.min(j)));
                    max_col = max_col.max(j);
                }
            }
        }

        // Problem guarantees at least one `1`, so unwrap is safe.
        let min_row = min_row.expect("grid contains at least one 1");
        let min_col = min_col.expect("grid contains at least one 1");

        let height = max_row - min_row + 1;
        let width = max_col - min_col + 1;

        (height * width) as i32
    }
}

//sub: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/submissions/1743817416/?envType=daily-question&envId=2025-08-22
//sol: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/solutions/7108103/3195-find-the-minimum-area-to-cover-all-eqxuw/
