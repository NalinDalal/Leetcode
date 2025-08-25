//498. Diagonal Traverse
impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let m = mat.len();
        if m == 0 {
            return vec![];
        }
        let n = mat[0].len();
        let mut result = Vec::with_capacity(m * n);

        for d in 0..(m + n - 1) {
            let mut diagonal = Vec::new();

            let mut r = if d < n { 0 } else { d + 1 - n };
            let mut c = if d < n { d } else { n - 1 };

            while r < m && c as isize >= 0 {
                diagonal.push(mat[r][c]);
                r += 1;
                if c == 0 {
                    break;
                }
                c -= 1;
            }

            if d % 2 == 0 {
                diagonal.reverse();
            }

            result.extend(diagonal);
        }

        result
    }
}

//sub: https://leetcode.com/problems/diagonal-traverse/submissions/1747259710/?envType=daily-question&envId=2025-08-25
//sol: https://leetcode.com/problems/diagonal-traverse/solutions/7119143/498-diagonal-traverse-by-nalindalal2004-xmc8/
