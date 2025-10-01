//1518. Water Bottles
impl Solution {
    pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
        let mut ans = num_bottles;
        let mut empty = num_bottles;

        while empty >= num_exchange {
            let new_bottles = empty / num_exchange;
            ans += new_bottles;
            empty = new_bottles + (empty % num_exchange);
        }

        ans
    }
}
//sub: https://leetcode.com/problems/water-bottles/submissions/1787961516/
//sol: https://leetcode.com/problems/water-bottles/solutions/7238540/1518-water-bottles-by-nalindalal2004-504n/
