//3147. Taking Maximum Energy From the Mystic Dungeon
impl Solution {
    pub fn maximum_energy(energy: Vec<i32>, k: i32) -> i32 {
        let n = energy.len();
        let k = k as usize;
        let mut dp = vec![0; n];
        let mut ans = i32::MIN;

        for i in (0..n).rev() {
            dp[i] = energy[i];
            if i + k < n {
                dp[i] += dp[i + k];
            }
            ans = ans.max(dp[i]);
        }

        ans
    }
}
//sub: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/submissions/1797126147/?envType=daily-question&envId=2025-10-10
//sol: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/solutions/7263748/3147-taking-maximum-energy-from-the-myst-2hzh/
