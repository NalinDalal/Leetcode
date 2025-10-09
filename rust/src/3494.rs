//3494. Find the Minimum Amount of Time to Brew Potions
impl Solution {
    pub fn min_time(skill: Vec<i32>, mana: Vec<i32>) -> i64 {
        let n = skill.len();
        let mut f = vec![0i64; n];

        for &x_i in mana.iter() {
            let x = x_i as i64;
            let mut now = f[0];

            // forward pass
            for i in 1..n {
                now = std::cmp::max(now + (skill[i - 1] as i64) * x, f[i]);
            }

            // last wizard finishes this potion
            f[n - 1] = now + (skill[n - 1] as i64) * x;

            // backward pass to update earlier wizards
            for i in (0..n - 1).rev() {
                f[i] = f[i + 1] - (skill[i + 1] as i64) * x;
            }
        }

        f[n - 1]
    }
}

//sub: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/submissions/1795933225/?envType=daily-question&envId=2025-10-09
//sol: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/solutions/7260546/3494-find-the-minimum-amount-of-time-to-tm0o9/
