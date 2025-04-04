//149. Max Points on a Line
use std::collections::HashMap;

impl Solution {
    pub fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 {
            a
        } else {
            Self::gcd(b, a % b)
        }
    }

    pub fn max_points(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        if n <= 1 {
            return n as i32;
        }

        let mut max_count = 1;

        for i in 0..n {
            let mut slope_map = HashMap::new();
            let mut duplicate = 1;
            let mut curr_max = 0;

            for j in i + 1..n {
                let dx = points[j][0] - points[i][0];
                let dy = points[j][1] - points[i][1];

                if dx == 0 && dy == 0 {
                    duplicate += 1;
                    continue;
                }

                let g = Self::gcd(dx, dy);
                let slope = (dy / g, dx / g);
                let count = slope_map.entry(slope).or_insert(0);
                *count += 1;
                curr_max = curr_max.max(*count);
            }

            max_count = max_count.max(curr_max + duplicate);
        }

        max_count
    }
}
// Example Usage
fn main() {
    let points = vec![
        vec![1, 1],
        vec![2, 2],
        vec![3, 3],
        vec![4, 1],
        vec![5, 2],
        vec![6, 3],
    ];
    println!("Max points on a straight line: {}", max_points(points));
}

//Sub: https://leetcode.com/problems/max-points-on-a-line/submissions/1596181922/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/max-points-on-a-line/solutions/6613216/149-max-points-on-a-line-by-nalindalal20-bjlx/
