//85. Maximal Rectangle
pub struct Solution;

impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.is_empty() || matrix[0].is_empty() {
            return 0;
        }

        let n = matrix.len();
        let m = matrix[0].len();
        let mut heights = vec![0; m];
        let mut max_area = 0;

        for i in 0..n {
            for j in 0..m {
                if matrix[i][j] == '1' {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            max_area = max_area.max(Self::largest_rectangle_area(&heights));
        }

        max_area
    }

    fn largest_rectangle_area(heights: &[i32]) -> i32 {
        let mut stack = Vec::new();
        let mut max_area = 0;
        let mut extended = heights.to_vec();
        extended.push(0); // Sentinel

        for (i, &h) in extended.iter().enumerate() {
            while let Some(&top) = stack.last() {
                if h < extended[top] {
                    stack.pop();
                    let height = extended[top];
                    let width = if let Some(&prev) = stack.last() {
                        (i - prev - 1) as i32
                    } else {
                        i as i32
                    };
                    max_area = max_area.max(height * width);
                } else {
                    break;
                }
            }
            stack.push(i);
        }

        max_area
    }
}
//sub: https://leetcode.com/problems/maximal-rectangle/submissions/1597140142/
//sol: https://leetcode.com/problems/maximal-rectangle/solutions/6617188/85-maximal-rectangle-by-nalindalal2004-ahgo/
