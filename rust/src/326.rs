//326. Power of Three
impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        if n <= 0 {
            return false;
        }
        let x = (n as f64).ln() / 3f64.ln();
        let diff = (x - x.round()).abs();
        diff < 1e-10
    }
}
//sub: https://leetcode.com/problems/power-of-three/submissions/1733186832/?envType=daily-question&envId=2025-08-13
//sol: https://leetcode.com/problems/power-of-three/solutions/7073579/326-power-of-three-by-nalindalal2004-4mj7/
