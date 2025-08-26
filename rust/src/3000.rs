//3000. Maximum Area of Longest Diagonal Rectangle
impl Solution {
    pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let mut max_diag_sq = 0;

        for rect in dimensions {
            let length = rect[0];
            let width = rect[1];
            let diag_sq = length * length + width * width;

            if diag_sq > max_diag_sq {
                max_diag_sq = diag_sq;
                ans = length * width;
            } else if diag_sq == max_diag_sq {
                ans = ans.max(length * width);
            }
        }

        ans
    }
}
//sub: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/submissions/1748422003/?envType=daily-question&envId=2025-08-26
//sol: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/solutions/7122777/3000-maximum-area-of-longest-diagonal-re-96wl/
