//869. Reordered Power of 2
impl Solution {
    pub fn reordered_power_of2(n: i32) -> bool {
        
    


    fn sig(x: i32) -> String {
        let mut chars: Vec<char> = x.to_string().chars().collect();
        chars.sort_unstable();
        chars.into_iter().collect()
    }

    let target = sig(n);
    for i in 0..31 {
        if sig(1 << i) == target {
            return true;
        }
    }
    false
}}

//sub: https://leetcode.com/problems/reordered-power-of-2/submissions/1729610058/?envType=daily-question&envId=2025-08-10
//sol: https://leetcode.com/problems/reordered-power-of-2/solutions/7062756/869-reordered-power-of-2-by-nalindalal20-j6kz/
