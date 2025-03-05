//2579. Count Total Number of Colored Cells

impl Solution {
    pub fn colored_cells(n: i32) -> i64 {
        1 + 4 * n as i64 * (n as i64 - 1) / 2
    }
}
//sub: https://leetcode.com/problems/count-total-number-of-colored-cells/submissions/1564018998/
//sol: https://leetcode.com/problems/count-total-number-of-colored-cells/solutions/6501548/2579-count-total-number-of-colored-cells-tt8f/
