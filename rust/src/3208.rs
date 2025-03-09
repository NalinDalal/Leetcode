//3208. Alternating Groups II
impl Solution {
    pub fn number_of_alternating_groups(colors: Vec<i32>, k: i32) -> i32 {
        let n = colors.len();
        let sz = n + k as usize - 1;
        let mut ans = 0;
        let mut alt = 1;
        let mut prev = colors[0];

        for i in 1..sz {
            alt = if prev == colors[i % n] { 1 } else { alt + 1 };
            if alt >= k as usize {
                ans += 1;
            }
            prev = colors[i % n];
        }

        ans
    }
}

// Example usage
fn main() {
    let colors = vec![0, 1, 0, 1, 0];
    let k = 3;
    println!("{}", Solution::number_of_alternating_groups(colors, k)); // Output: 5
}
//sub: https://leetcode.com/problems/alternating-groups-ii/submissions/1568065894/?envType=daily-question&envId=2025-03-09
//sol: https://leetcode.com/problems/alternating-groups-ii/solutions/6517274/3208-alternating-groups-ii-by-nalindalal-qqe4/
