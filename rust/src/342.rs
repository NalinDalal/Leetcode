//342. Power of Four
impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        if n <= 0 {
            return false;
        }
        let x = (n as f64).ln() / 4f64.ln();
        let diff = (x - x.round()).abs();
        diff < 1e-10        
    }
}
//sub: https://leetcode.com/problems/power-of-four/submissions/1735523233/?envType=daily-question&envId=2025-08-15
//sol: https://leetcode.com/problems/power-of-four/solutions/7081991/342-power-of-four-by-nalindalal2004-1gfn/ 
