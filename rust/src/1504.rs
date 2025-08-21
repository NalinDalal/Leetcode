//1504. Count Submatrices With All Ones
impl Solution {
    pub fn num_submat(mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let mut height = vec![0; n];
        let mut result = 0;

        for i in 0..m {
            // update heights
            for j in 0..n {
                if mat[i][j] == 0 {
                    height[j] = 0;
                } else {
                    height[j] += 1;
                }
            }

            // count rectangles ending at this row
            for j in 0..n {
                let mut min_height = height[j];
                let mut k = j as i32;
                while k >= 0 {
                    min_height = min_height.min(height[k as usize]);
                    if min_height == 0 {
                        break;
                    }
                    result += min_height;
                    k -= 1;
                }
            }
        }

        result
    }
}
//sub: https://leetcode.com/problems/count-submatrices-with-all-ones/submissions/1742685353/?envType=daily-question&envId=2025-08-21
//sol: https://leetcode.com/problems/count-submatrices-with-all-ones/solutions/7104935/1504-count-submatrices-with-all-ones-by-10iv1/
