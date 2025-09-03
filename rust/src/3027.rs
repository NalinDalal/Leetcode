//3027. Find the Number of Ways to Place People II
impl Solution {
    pub fn number_of_pairs(mut points: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        points.sort_by(|a, b| a[0].cmp(&b[0]).then(b[1].cmp(&a[1])));

        for i in 0..points.len() - 1 {
            let point_a = &points[i];
            let mut x_min = point_a[0] - 1;
            let x_max = i32::MAX;
            let mut y_min = i32::MIN;
            let y_max = point_a[1] + 1;

            for j in i + 1..points.len() {
                let point_b = &points[j];

                if point_b[0] > x_min && point_b[0] < x_max &&
                   point_b[1] > y_min && point_b[1] < y_max {
                    ans += 1;
                    x_min = point_b[0];
                    y_min = point_b[1];
                }
            }
        }
        ans
    }
}
//sub: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/submissions/1758210866/?envType=daily-question&envId=2025-09-03
//sol: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/solutions/7151371/3027-find-the-number-of-ways-to-place-pe-ds67/
