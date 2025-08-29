//3021. Alice and Bob Playing Flower Game
impl Solution {
    pub fn flower_game(n: i32, m: i32) -> i64 {
        let odd_n = (n + 1) / 2;
        let even_n = n / 2;
        let odd_m = (m + 1) / 2;
        let even_m = m / 2;

        (odd_n as i64) * (even_m as i64) + (even_n as i64) * (odd_m as i64)
    }
}

//sub: https://leetcode.com/problems/alice-and-bob-playing-flower-game/submissions/1751935200/?envType=daily-question&envId=2025-08-29
//sol: https://leetcode.com/problems/alice-and-bob-playing-flower-game/solutions/7133219/3021-alice-and-bob-playing-flower-game-b-na3r/
