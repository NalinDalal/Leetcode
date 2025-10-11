//118. Pascal's Triangle
impl Solution {
    pub fn pascal_triangle(row: i32) -> Vec<i64> {
        let mut ans = 1i64;
        let mut ans_row = vec![1];

        for col in 1..row {
            ans = ans * (row as i64 - col as i64) / col as i64;
            ans_row.push(ans);
        }

        ans_row
    }

    pub fn generate(n: i32) -> Vec<Vec<i64>> {
        let mut result = Vec::new();

        for i in 1..=n {
            result.push(Self::pascal_triangle(i));
        }

        result
    }
}

//sub: https://leetcode.com/problems/pascals-triangle/submissions/1719143411/?envType=daily-question&envId=2025-08-01
//sol: https://leetcode.com/problems/pascals-triangle/solutions/7030943/118-pascals-triangle-by-nalindalal2004-2n8b/

