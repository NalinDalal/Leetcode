//812. Largest Triangle Area
impl Solution {
    pub fn largest_triangle_area(points: Vec<Vec<i32>>) -> f64 {
        let n = points.len();
        let mut ans:f64 = 0.0;

        for i in 0..n {
            for j in i+1..n {
                for k in j+1..n {
                    ans = ans.max(area(&points[i], &points[j], &points[k]));
                }
            }
        }

        ans
    }
}

fn area(p: &Vec<i32>, q: &Vec<i32>, r: &Vec<i32>) -> f64 {
    (0.5 * ((p[0]*q[1] + q[0]*r[1] + r[0]*p[1]
           - p[1]*q[0] - q[1]*r[0] - r[1]*p[0]) as f64).abs())
}

//sub: https://leetcode.com/problems/largest-triangle-area/submissions/1783806404/?envType=daily-question&envId=2025-09-27
//sol: https://leetcode.com/problems/largest-triangle-area/solutions/7226991/812-largest-triangle-area-by-nalindalal2-o5u8/
