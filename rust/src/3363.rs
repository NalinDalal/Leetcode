//3363. Find the Maximum Number of Fruits Collected
impl Solution {
    pub fn max_collected_fruits(mut fruits: Vec<Vec<i32>>) -> i32 {
        let n = fruits.len();
        let mut ans = 0;

        // Diagonal sum (child at (0,0))
        for i in 0..n {
            ans += fruits[i][i];
        }

        let dp = |fruits: &Vec<Vec<i32>>| -> i32 {
            let mut prev = vec![i32::MIN; n];
            let mut curr = vec![i32::MIN; n];

            prev[n - 1] = fruits[0][n - 1];

            for i in 1..n - 1 {
                let start = std::cmp::max(n - 1 - i, i + 1);
                for j in start..n {
                    let mut best = prev[j];
                    if j >= 1 {
                        best = best.max(prev[j - 1]);
                    }
                    if j + 1 < n {
                        best = best.max(prev[j + 1]);
                    }
                    curr[j] = best + fruits[i][j];
                }
                std::mem::swap(&mut prev, &mut curr);
            }

            prev[n - 1]
        };

        ans += dp(&fruits);

        // Transpose the matrix (flip along main diagonal)
        for i in 0..n {
            for j in 0..i {
                let tmp = fruits[i][j];
                fruits[i][j] = fruits[j][i];
                fruits[j][i] = tmp;
            }
        }

        ans += dp(&fruits);
        ans
    }
}
//sub: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/submissions/1726432132/?envType=daily-question&envId=2025-08-07
//sol: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/solutions/7053308/3363-find-the-maximum-number-of-fruits-c-t5zg/
