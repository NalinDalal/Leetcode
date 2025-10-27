//2125. Number of Laser Beams in a Bank
impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut prev = 0;
        let mut ans = 0;

        for row in bank {
            let curr = row.chars().filter(|&ch| ch == '1').count() as i32;
            if curr > 0 {
                ans += prev * curr;
                prev = curr;
            }
        }

        ans
    }
}
//sub: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/submissions/1813307827/?envType=daily-question&envId=2025-10-27
//sol: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/solutions/7305870/2125-number-of-laser-beams-in-a-bank-by-s7g2o/
