//3025. Find the Number of Ways to Place People I
impl Solution {
    pub fn number_of_pairs(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut ans = 0;

        for i in 0..n {
            let a = &points[i];
            for j in 0..n {
                if i == j {
                    continue;
                }
                let b = &points[j];

                // A must be top-left, B must be bottom-right
                if !(a[0] <= b[0] && a[1] >= b[1]) {
                    continue;
                }

                // if only two points and orientation holds → valid
                if n == 2 {
                    ans += 1;
                    continue;
                }

                let mut illegal = false;
                for k in 0..n {
                    if k == i || k == j {
                        continue;
                    }
                    let p = &points[k];

                    let x_in = p[0] >= a[0] && p[0] <= b[0];
                    let y_in = p[1] <= a[1] && p[1] >= b[1];

                    if x_in && y_in {
                        illegal = true;
                        break;
                    }
                }

                if !illegal {
                    ans += 1;
                }
            }
        }

        ans
    }
}

//sub: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/submissions/1757048236/?envType=daily-question&envId=2025-09-02
//sol: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/solutions/7148156/3025-find-the-number-of-ways-to-place-pe-cw1y/
